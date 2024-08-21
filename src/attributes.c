/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file attributs.cc
 * @brief The main file of the project
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

void display_attribute_byte(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    signed char *value = (signed char *)calloc(i_att_len, sizeof(signed char));

    nc_get_att_schar(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%hhi\n", value[i_index]);
    free(value);
}

void display_attribute_char(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    char *value = (char *)calloc(i_att_len, sizeof(char));

    nc_get_att_text(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value = %s\n", value);
    free(value);
}

void display_attribute_short(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    short *value = (short *)calloc(i_att_len, sizeof(short));

    nc_get_att_short(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%hi\n", value[i_index]);
    free(value);
}

void display_attribute_int(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    int *value = (int *)calloc(i_att_len, sizeof(int));

    nc_get_att_int(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%i\n", value[i_index]);
    free(value);
}

void display_attribute_float(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    float *value = (float *)calloc(i_att_len, sizeof(float));

    nc_get_att_float(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%f\n", value[i_index]);
    free(value);
}

void display_attribute_double(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    double *value = (double *)calloc(i_att_len, sizeof(double));

    nc_get_att_double(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%f\n", value[i_index]);
    free(value);
}

void display_attribute_ubyte(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    unsigned char *value = (unsigned char *)calloc(i_att_len, sizeof(unsigned char));

    nc_get_att_ubyte(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%hhx\n", value[i_index]);
    free(value);
}

void display_attribute_ushort(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    unsigned short *value = (unsigned short *)calloc(i_att_len, sizeof(unsigned short));

    nc_get_att_ushort(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    free(value);
}

void display_attribute_uint(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    unsigned int *value = (unsigned int *)calloc(i_att_len, sizeof(unsigned int));

    nc_get_att_uint(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%u\n", value[i_index]);
    free(value);
}

void display_attribute_int64(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    long long *value = (long long *)calloc(i_att_len, sizeof(long long));

    nc_get_att_longlong(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%lli\n", value[i_index]);
    free(value);
}

void display_attribute_uint64(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    unsigned long long *value = (unsigned long long *)calloc(i_att_len, sizeof(unsigned long long));

    nc_get_att_ulonglong(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);
    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%llu\n", value[i_index]);
    free(value);
}

void display_attribute_string(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name)
{
    char **value = (char **)calloc(i_att_len, sizeof(char *));

    nc_get_att_string(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, value);

    printf("  - value =\n");
    for (size_t i_index = 0; i_index < i_att_len; i_index++)
        printf("%s\n", value[i_index]);
    free(value);
}

void display_attribute(file_informations *in_ps_file_infos, int32_t i_var_id, int32_t i_att_id, char *ac_tab)
{
    static void (*display_attribute[])(file_informations *in_ps_file_infos,
    int32_t i_var_id, size_t i_att_len, char *ac_att_name) = {
      NULL, &display_attribute_byte, &display_attribute_char, &display_attribute_short,
      &display_attribute_int, &display_attribute_float, &display_attribute_double,
      &display_attribute_ubyte, &display_attribute_ushort, &display_attribute_uint,
      &display_attribute_int64, &display_attribute_uint64, &display_attribute_string};
    char ac_att_name[NC_MAX_NAME + 1];
    nc_type i_type = 0;
    size_t i_att_len = 0;

    check_error(nc_inq_attname(in_ps_file_infos->i_file_id, i_var_id, i_att_id, ac_att_name));
    check_error(nc_inq_att(in_ps_file_infos->i_file_id, i_var_id, ac_att_name, &i_type, &i_att_len));
    printf(BOLD "%sAttribute %d:\n" RESET, ac_tab, i_att_id);
    printf("%s  - name = %s\n", ac_tab, ac_att_name);
    printf("%s  - type = %s\n", ac_tab, apc_type_list[((i_type > 12 || i_type < 0) ? 0 : i_type)]);
    printf("%s  - length = %zu\n%s", ac_tab, i_att_len, ac_tab);
    display_attribute[i_type](in_ps_file_infos, i_var_id, i_att_len, ac_att_name);
}

void display_globals_attributes(file_informations *in_ps_file_infos)
{
    printf("\n    " BOLD UNDERLINE "Globals attributes: %d\n" RESET, in_ps_file_infos->i_nb_attributes);
    for (int i_att_id = 0; i_att_id < in_ps_file_infos->i_nb_attributes; i_att_id++)
        display_attribute(in_ps_file_infos, NC_GLOBAL, i_att_id, "");
}
