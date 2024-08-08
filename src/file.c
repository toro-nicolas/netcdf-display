/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The main file of the project
*/
/**
 * @file file.c
 * @brief The file containing the NetCDF file functions
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

void open_file(char *str_path, int32_t i_mode, int32_t *pi_file_id)
{
    check_error(nc_open(str_path, i_mode, pi_file_id));
}

void get_infos(file_informations *in_ps_file_infos)
{
    check_error(nc_inq(in_ps_file_infos->i_file_id,
         &in_ps_file_infos->i_nb_dimensions, &in_ps_file_infos->i_nb_variables,
        &in_ps_file_infos->i_nb_attributes,
        &in_ps_file_infos->i_first_unlimited_dimensions_id));
}

void close_file(int32_t i_file_id)
{
    check_error(nc_close(i_file_id));
}
