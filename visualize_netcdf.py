from netCDF4 import Dataset
import numpy as np
import argparse
import os
import plotly.graph_objects as go
import plotly.express as px
from dash import Dash, dcc, html, Input, Output


def conv_tick(data):
    if data.dtype == '|S1':
        return (data[4]+data[5]).decode('ascii')
    else:
        return data
    

def generate_marks(max_value):
    step = 0
    for i in range(0, 1000, 10):
        if max_value <= i:
            step = i / 10
            break
    if step == 0:
        return {}
    marks = {i: str(i) for i in range(0, max_value + 1, int(step))}
    return marks


def get_2d_slice(array, index_list):
    sliced_data = array
    for index in index_list:
        sliced_data = np.take(sliced_data, index, axis=0)
    return sliced_data


app = Dash()
layout = []
inputs = []
variables_data = []
variables_info = []
flipud = False


def nc_info(args):

    file_tmp = args.file

    if args.file.endswith('.grb'):
        script_dir = os.path.dirname(os.path.abspath(__file__))
        os.system('python3 {0}/grib_to_netcdf.py {1} /tmp/netcdf_file.nc'.format(script_dir, args.file))
        file_tmp = '/tmp/netcdf_file.nc'

    with Dataset(file_tmp, 'r') as nc:
        print('File Format: {0}'.format(nc.file_format))

        print('\nGlobal Attributes:')
        for attr in nc.ncattrs():
            print("   {0}: {1}".format(attr, getattr(nc, attr)))

        print('\nDimensions:')
        for dimname, dim in nc.dimensions.items():
            print('   {} = {}'.format(dimname, dim))

        print('\nVariables:')
        for varname, var in nc.variables.items():
            print('   {0}: {1}'.format(varname, var.datatype))

            if len(var.shape) > 0:
                print('       shape: {}'.format(', '.join(str(x) for x in
var.shape)))
            print('       dimensions: {}'.format(str(var.dimensions)))

            for attr in var.ncattrs():
                print("       {0}: {1}".format(attr, getattr(var, attr)))

        print('\nNetCDF Data:')
        var_index = 0
        for varname, var in nc.variables.items():
            if len(var.shape) > 0:
                print('   {0}:'.format(varname))

                if var.datatype == 'S1':
                    vals = ''.join([val.tobytes().decode('utf-8') for val in np.ravel(var[:])])
                    print(vals)
                else:
                    if varname == "lat" or varname == "lon" or varname == "latitude" or varname == "longitude" or varname == "time" or varname == "depth" or varname == "step" or varname == "frequencies" or varname == "frequences" or varname == "immersions":
                        vals = []
                        for val in np.ravel(var[:]):
                            vals.append(val)
                    else:
                        vals = str(np.ravel(var[:])).replace('\n', '')
                    print(vals)

                    if var is not None:                        
                        data = var[:]
                        data = np.where((data > 10**30), np.nan, data)
                        if '_FillValue' in var.ncattrs():
                            fill_value = var._FillValue
                            data = np.where((data == fill_value), np.nan, data)

                        variables_data.append(data)
                        variables_info.append({"name": varname})
                        nb_dimensions = data.ndim
                        slicing_dimensions = max(0, nb_dimensions - 2)
                        if 'unit' in var.ncattrs():
                            variables_info[var_index]["unit"] = var.unit
                        elif 'units' in var.ncattrs():
                            variables_info[var_index]["unit"] = var.units
                        try:
                            variables_info[var_index]["x_name"] = nc.variables[var.dimensions[-1]].name
                            if 'unit' in nc.variables[var.dimensions[-1]].ncattrs():
                                variables_info[var_index]["x_unit"] = nc.variables[var.dimensions[-1]].unit
                            elif 'units' in nc.variables[var.dimensions[-1]].ncattrs():
                                variables_info[var_index]["x_unit"] = nc.variables[var.dimensions[-1]].units
                            variables_info[var_index]["x_data"] = nc.variables[var.dimensions[-1]][:]
                        except:
                            variables_info[var_index]["x_name"] = "x"
                            variables_info[var_index]["x_data"] = np.linspace(0, data.shape[-1], num=data.shape[-1])

                        if nb_dimensions > 1:
                            try:
                                variables_info[var_index]["y_name"] = nc.variables[var.dimensions[-2]].name
                                if 'unit' in nc.variables[var.dimensions[-2]].ncattrs():
                                    variables_info[var_index]["y_unit"] = nc.variables[var.dimensions[-2]].unit
                                elif 'units' in nc.variables[var.dimensions[-2]].ncattrs():
                                    variables_info[var_index]["y_unit"] = nc.variables[var.dimensions[-2]].units
                                variables_info[var_index]["y_data"] = nc.variables[var.dimensions[-2]][:]
                            except:
                                variables_info[var_index]["y_name"] = "y"
                                variables_info[var_index]["y_data"] = np.linspace(0, data.shape[-2], num=data.shape[-2])
                            
                        sliders = [
                            html.Div([
                                html.Label(f"Dimension {var.dimensions[dim_index]} of {varname}"),
                                dcc.Slider(
                                    id=f"slider-{var_index}-{dim_index}",
                                    min=0,
                                    max=data.shape[dim_index] - 1,
                                    step=1,
                                    value=0,
                                    marks=generate_marks(data.shape[dim_index] - 1),
                                )
                            ]) for dim_index in range(slicing_dimensions)
                        ]
                            
                        layout.extend(sliders)
                        for dim_index in range(slicing_dimensions):
                            inputs.append(Input(f'slider-{var_index}-{dim_index}', 'value'))
                        layout.append(dcc.Graph(id=f'slice-graph-{var_index}', style={"height": "100vh", "width": "100vw", "text-align": "center"}))
                        app.layout = html.Div(layout)
                        var_index += 1


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Visualize a NetCDF file.")
    parser.add_argument('file', type=str, help='The NetCDF file to visualize.')
    parser.add_argument('--flipud', action='store_true', help='Revert Up down on plot.')
    parser.add_argument('--vmin', type=int, default=0, help='The minimum value in the variable data.')
    parser.add_argument('--vmax', type=int, default=0, help='The maximum value in the variable data.')
    args = parser.parse_args()
    if args.flipud:
        flipud = True
    nc_info(args)


input_loop = True
for arr in variables_data:
    if len(arr.shape) > 2:
        input_loop = False
        break
if input_loop == True:
    inputs.append(Input('slice-graph-1', 'id'))
    print("ic")


@app.callback(
    [Output(f'slice-graph-{i}', 'figure') for i in range(len(variables_data))],
    inputs
)
def update_graph(*slider_values):
    print("Update graph")
    figures = []
    start_idx = 0
    
    for var_index, arr in enumerate(variables_data):
        slicing_dimensions = max(0, arr.ndim - 2)
        slice_index = slider_values[start_idx:start_idx + slicing_dimensions]
        
        sliced_data = get_2d_slice(arr, slice_index)
        
        if sliced_data.ndim == 2:
            if flipud:
                sliced_data = np.flipud(sliced_data)
            x_values = variables_info[var_index]['x_data']
            y_values = variables_info[var_index]['y_data']

            fig = px.imshow(
                sliced_data,  
                labels=dict(
                    x=variables_info[var_index]['x_name'] + (" [" + variables_info[var_index]['x_unit'] + "]" if "x_unit" in variables_info[var_index] else ""),
                    y=variables_info[var_index]['y_name'] + (" [" + variables_info[var_index]['y_unit'] + "]" if "y_unit" in variables_info[var_index] else ""),
                    color=variables_info[var_index]['name'] + (" [" + variables_info[var_index]['unit'] + "]" if "unit" in variables_info[var_index] else "")
                ),
                x=x_values,
                y=y_values, color_continuous_scale='Jet', 
                range_color=[args.vmin, args.vmax], 
                aspect='equal', origin='lower'
            )
            fig.update_layout(title=f"{variables_info[var_index]['name']}: 2D slice {slice_index if slice_index != () else ''}", autosize=True)
        elif sliced_data.ndim == 1:
            fig = go.Figure()
            text_labels = [variables_info[var_index]['name'] + (" [" + variables_info[var_index]['unit'] + "]" if "unit" in variables_info[var_index] else "") + f": {val}" for val in sliced_data]

            x_values = variables_info[var_index]['x_data']
            for index in range(len(text_labels)):
                text_labels[index] = f"Slice: {index}<br>" + text_labels[index]

            fig.add_trace(go.Scatter(
                y=sliced_data,
                mode='lines+markers',
                text=text_labels,
                hoverinfo='text'
            ))

            fig.update_layout(
                xaxis_title="Slice",
                yaxis_title=variables_info[var_index]['name'] + (" [" + variables_info[var_index]['unit'] + "]" if "unit" in variables_info[var_index] else ""),
                xaxis=dict(tickmode='auto'),
                yaxis=dict(tickmode='auto'),
                title=f"{variables_info[var_index]['name']}: 1D slice {slice_index if slice_index != () else ''}"
            )
        else:
            fig = go.Figure()
            fig.update_layout(title=f"{variables_info[var_index]['name']}: Error")
        
        figures.append(fig)
        start_idx += slicing_dimensions
    
    return figures


app.run_server(debug=False)
