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

void display_invalid_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    printf("Unsupported variable type.\n");
}

void display_byte_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    char *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(char));
        check_error(nc_get_vara_schar(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %hhi\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_char_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    char *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(char));
        check_error(nc_get_vara_text(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %c\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_short_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    short *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(short));
        check_error(nc_get_vara_short(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %hi\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_int_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    int *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(int));
        check_error(nc_get_vara_int(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %i\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_float_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    float *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(float));
        check_error(nc_get_vara_float(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %f\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_double_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    double *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(double));
        check_error(nc_get_vara_double(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %.50f\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_ubyte_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    unsigned char *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(unsigned char));
        check_error(nc_get_vara_ubyte(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %hhx\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_ushort_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    unsigned short *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(unsigned short));
        check_error(nc_get_vara_ushort(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %hu\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_uint_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    unsigned int *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(unsigned int));
        check_error(nc_get_vara_uint(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %u\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_int64_variable(int32_t i_file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    long long *value = NULL;

    for (size_t i_index = 0; i_index < s_current_var->i_data_size; i_index++) {
        value = calloc(1, sizeof(long long));
        check_error(nc_get_vara_longlong(i_file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %lli\n", value[0]);
        }
        free(value);
        if (i_index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_uint64_variable(int32_t file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
     	unsigned long long *value = NULL;

    for (size_t index = 0; index < s_current_var->i_data_size; index++) {
        value = calloc(1, sizeof( 	unsigned long long ));
        check_error(nc_get_vara_ulonglong(file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %llu\n", value[0]);
        }
        free(value);
        if (index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
                    break;
                }
            }
        }
    }
}

void display_string_variable(int32_t file_id, variable_informations_s *s_current_var,
    size_t *ai_count, size_t *ai_start)
{
    char **value = NULL;

    for (size_t index = 0; index < s_current_var->i_data_size; index++) {
        value = calloc(1, sizeof(char *));
        check_error(nc_get_vara_string(file_id, s_current_var->i_id, ai_start, ai_count, value));
        printf("Value[");
        for (int32_t i_index = 0; i_index < s_current_var->i_ndims; i_index++) {
            printf("%zu", ai_start[i_index]);
            if (i_index + 1 < s_current_var->i_ndims)
                printf(", ");
            else
                printf("]: %s\n", value[0]);
        }
        free(value);
        if (index + 1 < s_current_var->i_data_size) {
            for (int start_index = s_current_var->i_ndims - 1; start_index > -1; start_index++) {
                if (ai_start[start_index] + 1 == s_current_var->ai_dims_size[start_index]) {
                    ai_start[start_index] = 0;
                    ai_start[start_index - 1] += 1;
                } else {
                    ai_start[start_index] += 1;
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
    size_t *start = calloc(current_var->i_ndims, sizeof(size_t));

    printf("  - content =\n");
    for (int count_index = 0; count_index < NC_MAX_VAR_DIMS; count_index++)
        count[count_index] = 1;
    if (current_var->i_type > 12)
        current_var->i_type = 0;
    display_functions[current_var->i_type](file_id, current_var, count, start);
    free(start);
}

void display_variables(file_informations *in_ps_file_infos, settings_t *ps_settings)
{
    char ac_dim_name[MAX_NC_NAME + 1] = {0};

    printf("\n    " BOLD UNDERLINE "Variables: %d\n" RESET, in_ps_file_infos->i_nb_variables);
    for (int var = 0; var < in_ps_file_infos->i_nb_variables; var++) {
        variable_informations_s s_current_var = {0};
        s_current_var.i_id = var;
        s_current_var.i_data_size = 1;

        check_error(nc_inq_var(in_ps_file_infos->i_file_id, s_current_var.i_id,
          s_current_var.ac_var_name, &s_current_var.i_type, &s_current_var.i_ndims,
          s_current_var.ai_dimids, &s_current_var.i_natts));
        printf(BOLD "Variable %d:\n" RESET, s_current_var.i_id);
        printf("  - name = %s\n", s_current_var.ac_var_name);
        printf("  - type = %s\n", apc_type_list[
            ((s_current_var.i_type > 12 || s_current_var.i_type < 0) ? 0 : s_current_var.i_type)]);
        printf("  - number of dims = %i\n", s_current_var.i_ndims);
        if (s_current_var.i_ndims > 0) {
            printf("  - dims ids = [");
            for (int32_t i_index = 0; i_index < s_current_var.i_ndims; i_index++) {
                printf("%i", s_current_var.ai_dimids[i_index]);
                if (i_index + 1 < s_current_var.i_ndims)
                    printf(", ");
                else
                    printf("]\n");
            }
            printf("  - dims name = [");
            for (int32_t i_index = 0; i_index < s_current_var.i_ndims; i_index++) {
                nc_inq_dimname(in_ps_file_infos->i_file_id,
                    s_current_var.ai_dimids[i_index], ac_dim_name);
                printf("%s", ac_dim_name);
                if (i_index + 1 < s_current_var.i_ndims)
                    printf(", ");
                else
                    printf("]\n");
            }
        }
        for (int i_index = 0; i_index < s_current_var.i_ndims; i_index++)
            check_error(nc_inq_dimlen(in_ps_file_infos->i_file_id,
            s_current_var.ai_dimids[i_index], &s_current_var.ai_dims_size[i_index]));
        for (int index = 0; index < s_current_var.i_ndims; index++)
            s_current_var.i_data_size *= s_current_var.ai_dims_size[index];
        printf("  - data size = %zu\n", s_current_var.i_data_size);
        if (ps_settings->b_attribute) {
            for (int i_att_id = 0; i_att_id < s_current_var.i_natts; i_att_id++)
                display_attribute(in_ps_file_infos, s_current_var.i_id, i_att_id, TAB);
        }
        if (ps_settings->b_content && s_current_var.i_data_size != 0 && s_current_var.i_ndims != 0)
            display_variables_values(in_ps_file_infos->i_file_id, &s_current_var);
    }
}

