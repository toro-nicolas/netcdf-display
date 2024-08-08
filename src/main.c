/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The main file of the project
*/
/**
 * @file main.c
 * @brief The main file of the project
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

int main(int argc, char **argv)
{
    file_informations file_infos = {0};

    if (argc < 2)
        exit(1);
    open_file(argv[1], NC_NOWRITE, &file_infos.file_id);
    get_infos(&file_infos);
    if (argc > 2)
        display_all(&file_infos, true);
    else
        display_all(&file_infos, false);
    printf("Unlimited dimension ID: %d\n", file_infos.unlimited_dimensions_id);
    close_file(file_infos.file_id);
}
