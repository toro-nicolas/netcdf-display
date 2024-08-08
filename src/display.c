/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The file containing the display informations functions
*/
/**
 * @file display.c
 * @brief The file containing the display informations functions
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

void display_dimensions(file_informations *file_infos)
{
    printf("\033[1m\nDimensions: %d\n\033[0m", file_infos->nb_dimensions);
    for (int dim = 0; dim < file_infos->nb_dimensions; dim++) {
        char dim_name[NC_MAX_NAME + 1];
        size_t dim_len = 0;

        check_error(nc_inq_dim(file_infos->file_id, dim, dim_name, &dim_len));
        printf("Dimension %d: name = %s, length = %zu\n", dim, dim_name, dim_len);
    }
}

void display_invalid_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    printf("Unsupported variable type.\n");
}

void display_byte_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    char *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(char));
        check_error(nc_get_vara_schar(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %hhx\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_char_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    char *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(char));
        check_error(nc_get_vara_text(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %c\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_short_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    short *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(short));
        check_error(nc_get_vara_short(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %hd\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_int_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    int *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(int));
        check_error(nc_get_vara_int(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %d\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_float_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    float *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(float));
        check_error(nc_get_vara_float(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %f\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_double_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    double *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(double));
        check_error(nc_get_vara_double(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %.45f\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_ubyte_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    unsigned char *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(unsigned char));
        check_error(nc_get_vara_ubyte(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %hhx\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_ushort_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    unsigned short *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(unsigned short));
        check_error(nc_get_vara_ushort(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %hd\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_uint_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    unsigned int *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(unsigned int));
        check_error(nc_get_vara_uint(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %u\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_int64_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    long long *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(long long));
        check_error(nc_get_vara_longlong(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %lld\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_uint64_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
     	unsigned long long *value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof( 	unsigned long long ));
        check_error(nc_get_vara_ulonglong(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %llu\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_string_variable(int file_id, variable_informations_s *current_var,
    size_t *count, size_t *start)
{
    char **value = NULL;

    for (size_t index = 0; index < current_var->data_size; index++) {
        value = calloc(1, sizeof(char *));
        check_error(nc_get_vara_string(file_id, current_var->id, start, count, value));
        printf("Value[%zu]: %s\n", index, value[0]);
        free(value);
        if (index + 1 < current_var->data_size) {
            for (int start_index = current_var->ndims - 1; start_index > -1; start_index++) {
                if (start[start_index] + 1 == current_var->dims_size[start_index]) {
                    start[start_index] = 0;
                    start[start_index - 1] += 1;
                } else {
                    start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_variables_values(int file_id, variable_informations_s *current_var)
{
    static void (*display_functions[])(int file_id,
    variable_informations_s *current_var, size_t *count, size_t *start) = {
      &display_invalid_variable, &display_byte_variable, &display_char_variable,
      &display_short_variable, &display_int_variable,
      &display_float_variable, &display_double_variable, &display_ubyte_variable,
      &display_ushort_variable, &display_uint_variable, &display_int64_variable,
      &display_uint64_variable, &display_string_variable};
    static size_t count[NC_MAX_VAR_DIMS] = {0};
    size_t *start = calloc(current_var->ndims, sizeof(size_t));

    for (int count_index = 0; count_index < NC_MAX_VAR_DIMS; count_index++)
        count[count_index] = 1;
    if (current_var->type > 12)
        current_var->type = 0;
    display_functions[current_var->type](file_id, current_var, count, start);
    free(start);
}

void display_variables(file_informations *file_infos, bool display_data)
{
    int error = 0;
    double *data = NULL;

    printf("\033[1m\nVariables: %d\n\033[0m", file_infos->nb_variables);
    for (int var = 0; var < file_infos->nb_variables; var++) {
        variable_informations_s current_var = {0};
        current_var.id = var;
        current_var.data_size = 1;

        check_error(nc_inq_var(file_infos->file_id, current_var.id,
          current_var.var_name, &current_var.type, &current_var.ndims,
          current_var.dimids, &current_var.natts));
        printf("Variable %d: name = %s, type = %i, ndims = %i, dimids = %p, natts = %i\n",
          current_var.id, current_var.var_name, current_var.type,
          current_var.ndims, current_var.dimids, current_var.natts);
        for (int index = 0; index < current_var.ndims; index++)
            check_error(nc_inq_dimlen(file_infos->file_id,
            current_var.dimids[index], &current_var.dims_size[index]));
        for (int index = 0; index < current_var.ndims; index++)
            current_var.data_size *= current_var.dims_size[index];
        printf("Data size: %zu\n", current_var.data_size);
        if (display_data == true)
            display_variables_values(file_infos->file_id, &current_var);
    }
}

void display_attribute_values(int file_id, int varid, const char *att_name, nc_type type, size_t len)
{
    switch (type) {
        case NC_CHAR: {
            char *value = calloc(len, sizeof(char));
            check_error(nc_get_att_text(file_id, varid, att_name, value));
            printf("Value: %s\n", value);
            free(value);
            break;
        }
        case NC_INT: {
            int *value = calloc(len, sizeof(int));
            check_error(nc_get_att_int(file_id, varid, att_name, value));
            for (size_t index = 0; index < len; index++)
                printf("Value[%zu]: %d\n", index, value[index]);
            free(value);
            break;
        }
        case NC_FLOAT: {
            float *value = calloc(len, sizeof(float));
            check_error(nc_get_att_float(file_id, varid, att_name, value));
            for (size_t index = 0; index < len; index++)
                printf("Value[%zu]: %f\n", index, value[index]);
            free(value);
            break;
        }
        case NC_DOUBLE: {
            double *value = calloc(len, sizeof(double));
            check_error(nc_get_att_double(file_id, varid, att_name, value));
            for (size_t index = 0; index < len; index++)
                printf("Value[%zu]: %lf\n", index, value[index]);
            free(value);
            break;
        }
        default:
            printf("Unsupported attribute type.\n");
    }
}


void display_attributes(file_informations *file_infos)
{
    printf("\033[1m\nAttributes: %d\n\033[0m", file_infos->nb_attributes);
    for (int att = 0; att < file_infos->nb_attributes; att++) {
        char att_name[NC_MAX_NAME + 1];
        nc_type type = 0;
        size_t att_len = 0;

        check_error(nc_inq_attname(file_infos->file_id, NC_GLOBAL, att, att_name));
        check_error(nc_inq_att(file_infos->file_id, NC_GLOBAL, att_name, &type, &att_len));
        printf("Attribute %d: name = %s, type = %i length = %zu\n", att, att_name, type, att_len);
        display_attribute_values(file_infos->file_id, NC_GLOBAL, att_name, type, att_len);
    }
}

void display_all(file_informations *file_infos, bool data)
{
    printf("\033[1mDisplay all informations of the file :\n\033[0m");
    display_dimensions(file_infos);
    display_variables(file_infos, data);
    display_attributes(file_infos);
}
