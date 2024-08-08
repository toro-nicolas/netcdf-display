/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The main file of the project
*/
/**
 * @file file.c
 * @brief The file containing the error handling functions
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

void check_error(int error)
{
    if (error != 0) {
        fprintf(stderr, "%s\n", nc_strerror(error));
        exit(1);
    }
}
