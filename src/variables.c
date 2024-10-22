/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The file containing the variables functions
*/
/**
 * @file variables.c
 * @brief The file containing the variables functions
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

/**
 * @brief Display a value of an invalid variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_invalid_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                              size_t *in_ai_count, size_t *in_ai_start)
{
    printf("Unsupported variable type.\n");
}

/**
 * @brief Display a value of a byte variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_byte_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                           size_t *in_ai_count, size_t *in_ai_start)
{
    signed char *value = calloc(1, sizeof(signed char));

    ERROR(nc_get_vara_schar(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%hhi", value[0]);
    free(value);
}

/**
 * @brief Display a value of a char variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_char_variable(int32_t in_i_file_id, variable_information_t *in_s_current_var,
                           size_t *in_ai_count, size_t *in_ai_start)
{
    char *value = calloc(1, sizeof(char));

    ERROR(nc_get_vara_text(in_i_file_id, in_s_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%c", value[0]);
    free(value);
}

/**
 * @brief Display a value of a short variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_short_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                            size_t *in_ai_count, size_t *in_ai_start)
{
    short *value = calloc(1, sizeof(short));

    ERROR(nc_get_vara_short(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%hi", value[0]);
    free(value);
}

/**
 * @brief Display a value of an int variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_int_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                          size_t *in_ai_count, size_t *in_ai_start)
{
    int *value = calloc(1, sizeof(int));

    ERROR(nc_get_vara_int(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%i", value[0]);
    free(value);
}

/**
 * @brief Display a value of a float variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_float_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                            size_t *in_ai_count, size_t *in_ai_start)
{
    float *value = calloc(1, sizeof(float));

    ERROR(nc_get_vara_float(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%f", value[0]);
    free(value);
}

/**
 * @brief Display a value of a double variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_double_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                             size_t *in_ai_count, size_t *in_ai_start)
{
    double *value = calloc(1, sizeof(double));

    ERROR(nc_get_vara_double(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%f", value[0]);
    free(value);
}

/**
 * @brief Display a value of an ubyte variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_ubyte_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                            size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned char *value = calloc(1, sizeof(unsigned char));

    ERROR(nc_get_vara_ubyte(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%hhx", value[0]);
    free(value);
}

/**
 * @brief Display a value of an ushort variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_ushort_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                             size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned short *value = calloc(1, sizeof(unsigned short));

    ERROR(nc_get_vara_ushort(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%hu", value[0]);
    free(value);
}

/**
 * @brief Display a value of an uint variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_uint_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                           size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned int *value = calloc(1, sizeof(unsigned int));

    ERROR(nc_get_vara_uint(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%u", value[0]);
    free(value);
}

/**
 * @brief Display a value of an int64 variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_int64_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                            size_t *in_ai_count, size_t *in_ai_start)
{
    long long *value = calloc(1, sizeof(long long));

    ERROR(nc_get_vara_longlong(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%lli", value[0]);
    free(value);
}

/**
 * @brief Display a value of an uint64 variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_uint64_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                             size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned long long *value = calloc(1, sizeof(unsigned long long));

    ERROR(nc_get_vara_ulonglong(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%llu", value[0]);
    free(value);
}

/**
 * @brief Display a value of a string variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void display_string_variable(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                             size_t *in_ai_count, size_t *in_ai_start)
{
    char **value = calloc(1, sizeof(char *));

    ERROR(nc_get_vara_string(in_i_file_id, in_ps_current_var->i_id, in_ai_start, in_ai_count, value));
    printf("%s", value[0]);
    free(value);
}

/**
 * @brief Display the values in a variable
 * @param in_i_file_id The file id
 * @param in_ps_current_var The current variable to display
 * @param in_b_raw The raw display flag
 * @return <b>void</b>
 */
void display_variables_values(int32_t in_i_file_id, variable_information_t *in_ps_current_var,
                              bool in_b_raw)
{
    static void (*display_functions[])(int32_t in_i_file_id,
    variable_information_t *in_ps_current_var, size_t *in_ai_count, size_t *in_ai_start) = {
      &display_invalid_variable, &display_byte_variable, &display_char_variable,
      &display_short_variable, &display_int_variable,
      &display_float_variable, &display_double_variable, &display_ubyte_variable,
      &display_ushort_variable, &display_uint_variable, &display_int64_variable,
      &display_uint64_variable, &display_string_variable};
    static size_t ai_count[NC_MAX_VAR_DIMS] = {0};
    size_t *ai_start = calloc(in_ps_current_var->i_ndims, sizeof(size_t));

    printf("  - content =\n");
    for (int32_t i_count_index = 0; i_count_index < NC_MAX_VAR_DIMS; i_count_index++)
        ai_count[i_count_index] = 1;
    if (in_ps_current_var->i_type > 12)
        in_ps_current_var->i_type = 0;
    for (size_t i_index = 0; i_index < in_ps_current_var->i_data_size; i_index++) {
        if (in_b_raw) {
            printf("Value[");
            for (int32_t i_dim_index = 0;
                 i_dim_index < in_ps_current_var->i_ndims; i_dim_index++) {
                printf("%zu", ai_start[i_dim_index]);
                if (i_dim_index + 1 < in_ps_current_var->i_ndims)
                    printf(", ");
                else {
                    printf("]: ");
                    display_functions[in_ps_current_var->i_type](in_i_file_id,
                        in_ps_current_var, ai_count, ai_start);
                    putchar('\n');
                }
            }
        } else {
            for (int32_t i_start_index = in_ps_current_var->i_ndims - 1; ai_start[0] == 0 && i_start_index > -1; i_start_index--) {
                bool b_tmp_skip = false;
                for (int32_t i_tmp_index = i_start_index; i_tmp_index > -1; i_tmp_index--) {
                    if (ai_start[i_tmp_index] != 0)
                        b_tmp_skip = true;
                }
                if (b_tmp_skip)
                    continue;
                for (int32_t i_tmp_index = 0; i_tmp_index < ((in_ps_current_var->i_ndims - i_start_index - 1) * 4); i_tmp_index++)
                    putchar(' ');
                putchar('[');
                if (i_start_index != 0 && i_start_index != in_ps_current_var->i_ndims - 1) {
                    printf(" %s = %zu:", in_ps_current_var->aac_dims_name[i_start_index + 1], ai_start[i_start_index + 1]);
                }
                if (i_start_index != 0)
                    putchar('\n');
            }
            display_functions[in_ps_current_var->i_type](in_i_file_id,
                in_ps_current_var, ai_count, ai_start);
            for (int32_t i_end_index = 0; i_end_index < in_ps_current_var->i_ndims; i_end_index++) {
                if (ai_start[i_end_index] + 1 == in_ps_current_var->ai_dims_size[i_end_index]) {
                    if (i_end_index != 0) {
                        for (int32_t i_tmp_index = 0; i_tmp_index < ((in_ps_current_var->i_ndims - i_end_index - 1) * 4); i_tmp_index++)
                            putchar(' ');
                    }
                    putchar(']');
                    putchar('\n');
                } else if (i_end_index == 0) {
                    putchar(',');
                    putchar(' ');
                    break;
                } else
                    break;
            }
        }
        for (int i_start_index = 0; i_start_index < in_ps_current_var->i_ndims
        && i_index + 1 < in_ps_current_var->i_data_size; i_start_index++) {
            if ((ai_start[i_start_index] + 1 == in_ps_current_var->ai_dims_size[i_start_index] && i_start_index == 0)
            || ai_start[i_start_index] == in_ps_current_var->ai_dims_size[i_start_index]) {
                ai_start[i_start_index] = 0;
                ai_start[i_start_index + 1] += 1;
            } else if (i_start_index == 0) {
                ai_start[i_start_index] += 1;
                break;
            }
        }
    }
    free(ai_start);
}

/**
 * @brief Display the variables of the file
 * @param in_ps_file_infos The file informations
 * @param in_ps_settings The display settings
 * @return <b>void</b>
 */
void display_variables(file_information_t *in_ps_file_infos, settings_t *in_ps_settings)
{
    printf("\n    " BOLD UNDERLINE "Variables: %d\n" RESET, in_ps_file_infos->i_nb_variables);
    for (int var = 0; var < in_ps_file_infos->i_nb_variables; var++) {
        variable_information_t s_current_var = {0};
        s_current_var.i_id = var;
        s_current_var.i_data_size = 1;

        ERROR(nc_inq_var(in_ps_file_infos->i_file_id, s_current_var.i_id,
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
                ERROR(nc_inq_dimname(in_ps_file_infos->i_file_id,
                    s_current_var.ai_dimids[i_index], s_current_var.aac_dims_name[i_index]));
                printf("%s", s_current_var.aac_dims_name[i_index]);
                if (i_index + 1 < s_current_var.i_ndims)
                    printf(", ");
                else
                    printf("]\n");
            }
        }
        for (int i_index = 0; i_index < s_current_var.i_ndims; i_index++)
            ERROR(nc_inq_dimlen(in_ps_file_infos->i_file_id,
            s_current_var.ai_dimids[i_index], &s_current_var.ai_dims_size[i_index]));
        for (int index = 0; index < s_current_var.i_ndims; index++)
            s_current_var.i_data_size *= s_current_var.ai_dims_size[index];
        printf("  - data size = %zu\n", s_current_var.i_data_size);
        if (in_ps_settings->b_attribute) {
            for (int i_att_id = 0; i_att_id < s_current_var.i_natts; i_att_id++)
                display_attribute(in_ps_file_infos, s_current_var.i_id, i_att_id, TAB);
        }
        if (in_ps_settings->b_content && s_current_var.i_data_size != 0 && s_current_var.i_ndims != 0)
            display_variables_values(in_ps_file_infos->i_file_id, &s_current_var, in_ps_settings->b_raw);
    }
}

