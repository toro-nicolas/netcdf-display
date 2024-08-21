/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The header file of the project
*/
/**
 * @file nc_display.h
 * @brief The header file of the project
 * @author Nicolas TORO
 */

#include <netcdf.h>
//#include <hdf5.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <getopt.h>

#ifndef NC_DISPLAY_H_
    #define NC_DISPLAY_H_

    #define RED "\033[0;31m"
    #define GREEN "\033[0;32m"
    #define YELLOW "\033[0;33m"
    #define BOLD "\033[1m"
    #define UNDERLINE "\033[4m"
    #define RESET "\033[0m"

typedef struct settings_s {
    bool b_global_attributes;
    bool b_dimension;
    bool b_variable;
    bool b_attribute;
    bool b_content;
    char *ac_file;
} settings_t;

typedef struct file_informations_s {
    int32_t i_file_id;
    int32_t i_nb_dimensions;
    int32_t i_nb_variables;
    int32_t i_nb_attributes;
    int32_t i_first_unlimited_dimensions_id;
} file_informations;

typedef struct variable_informations_s {
    int32_t i_id;
    char ac_var_name[NC_MAX_NAME + 1];
    nc_type i_type;
    int32_t i_ndims;
    int32_t ai_dimids[NC_MAX_VAR_DIMS];
    int32_t i_natts;
    size_t ai_dims_size[NC_MAX_VAR_DIMS];
    size_t i_data_size;
} variable_informations_s;

extern const char *apc_type_list[];


void display_dimensions(file_informations *in_ps_file_info);
void display_attribute(file_informations *in_ps_file_infos, int32_t i_var_id, int32_t i_nb_attributes);
void display_globals_attributes(file_informations *in_ps_file_infos);
void display_variables(file_informations *in_ps_file_infos, settings_t *ps_settings);
void check_error(int error);
void open_file(char *path, int mode, int *file_id);
void get_infos(file_informations *file_infos);
void close_file(int file_id);

#endif /* NC_DISPLAY_H_ */
