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
#include <wait.h>
#include <libgen.h>
#include <linux/limits.h>

#ifndef NC_DISPLAY_H_
    #define NC_DISPLAY_H_

    #define TAB "    "
    #ifdef COLOR
        #define RED "\033[0;31m"
        #define GREEN "\033[0;32m"
        #define YELLOW "\033[0;33m"
        #define BOLD "\033[1m"
        #define UNDERLINE "\033[4m"
        #define RESET "\033[0m"
    #else
        #define RED ""
        #define GREEN ""
        #define YELLOW ""
        #define BOLD ""
        #define UNDERLINE ""
        #define RESET ""
    #endif
    #define ERROR(ec) check_error(ec, __FILE__, __LINE__, __func__)

/* The settings structure */
typedef struct settings_s {
    bool b_global_attributes; /* Display the global attributes */
    bool b_dimension; /* Display the dimensions */
    bool b_variable; /* Display the variables */
    bool b_attribute; /* Display the attributes */
    bool b_content; /* Display the content */
    bool b_raw; /* Change display style */
    char *ac_file; /* The file path */
} settings_t;

/* The file information structure */
typedef struct file_information_s {
    int32_t i_file_id; /* The file id */
    int32_t i_nb_dimensions; /* The number of dimensions */
    int32_t i_nb_variables; /* The number of variables */
    int32_t i_nb_attributes; /* The number of attributes */
    int32_t i_first_unlimited_dimensions_id; /* The first unlimited dimension id */
} file_information_t;

/* The variable information structure */
typedef struct variable_information_s {
    int32_t i_id; /* The variable id */
    char ac_var_name[NC_MAX_NAME + 1]; /* The variable name */
    nc_type i_type; /* The variable type */
    int32_t i_ndims; /* The number of dimensions */
    int32_t ai_dimids[NC_MAX_VAR_DIMS]; /* The dimensions ids */
    int32_t i_natts; /* The number of attributes */
    size_t ai_dims_size[NC_MAX_VAR_DIMS]; /* The dimensions sizes */
    size_t i_data_size; /* The data size */
    char aac_dims_name[NC_MAX_VAR_DIMS][NC_MAX_NAME + 1]; /* The dimensions names */
} variable_information_t;

/* The list of NetCDF types */
extern const char *apc_type_list[];


    /* File functions */

/**
 * @brief Check if there is an error
 * @param in_i_error The error code
 * @param in_ac_file The file name
 * @param in_i_line The line number
 * @param in_ac_func The function name
 * @return <b>void</b>
 */
void check_error(int in_i_error, const char *in_ac_file,
                 const int in_i_line, const char *in_ac_func);

/**
 * @brief Open a NetCDF file or a GRIB file
 * @param in_str_path The file path
 * @param in_i_mode The mode to open the file
 * @param in_pi_file_id The file id
 * @return <b>void</b>
 */
void open_file(char *in_str_path, int32_t in_i_mode, int32_t *in_pi_file_id);

/**
 * @brief Get the informations of the file
 * @param in_ps_file_infos The file informations
 * @return <b>void</b>
 */
void get_infos(file_information_t *in_ps_file_infos);

/**
 * @brief Close a file
 * @param in_i_file_id The file id
 * @return <b>void</b>
 */
void close_file(int32_t in_i_file_id);



    /* Display functions */

/**
 * @brief Display the dimensions of the file
 * @param in_ps_file_infos The file informations
 * @return <b>void</b>
 */
void display_dimensions(file_information_t *in_ps_file_infos);

/**
 * @brief Display the attributes of a variable
 * @param in_ps_file_infos The file informations
 * @param in_i_var_id The variable id
 * @param in_i_nb_attributes The number of attributes
 * @param in_ac_tab The tabulation
 * @return <b>void</b>
 */
void display_attribute(file_information_t *in_ps_file_infos, int32_t i_var_id,
                       int32_t i_att_id, char *ac_tab);

/**
 * @brief Display the global attributes of the file
 * @param in_ps_file_infos The file informations
 * @return <b>void</b>
 */
void display_globals_attributes(file_information_t *in_ps_file_infos);

/**
 * @brief Display the variables of the file
 * @param in_ps_file_infos The file informations
 * @param in_ps_settings The display settings
 * @return <b>void</b>
 */
void display_variables(file_information_t *in_ps_file_infos, settings_t *in_ps_settings);

#endif /* NC_DISPLAY_H_ */
