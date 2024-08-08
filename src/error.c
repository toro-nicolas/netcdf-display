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
        fprintf(stderr, "\033[0;31m\033[1m%s\033[0m\n", nc_strerror(error));
        exit(1);
    }
}
