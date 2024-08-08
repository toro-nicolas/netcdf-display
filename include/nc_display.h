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

#ifndef NC_DISPLAY_H_
    #define NC_DISPLAY_H_

typedef struct file_informations_s {
    int file_id;
    int nb_dimensions;
    int nb_variables;
    int nb_attributes;
    int unlimited_dimensions_id;
} file_informations;

typedef struct variable_informations_s {
    int id;
    char var_name[NC_MAX_NAME + 1];
    nc_type type;
    int ndims;
    int dimids[NC_MAX_VAR_DIMS];
    int natts;
    size_t dims_size[NC_MAX_VAR_DIMS];
    size_t data_size;
} variable_informations_s;

void display_all(file_informations *file_infos, bool data);
void check_error(int error);
void open_file(char *path, int mode, int *file_id);
void get_infos(file_informations *file_infos);
void close_file(int file_id);

#endif /* NC_DISPLAY_H_ */
