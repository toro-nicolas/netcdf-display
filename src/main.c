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

const char *apc_type_list[] = {"Unknown", "Byte", "Char", "Short", "Int",
    "Float", "Double", "UByte", "UShort", "UInt", "Int64", "UInt64", "String"};

int main(int argc, char **argv)
{
    file_informations s_file_infos = {0};

    if (argc < 2)
        exit(1);
    open_file(argv[1], NC_NOWRITE, &s_file_infos.i_file_id);
    get_infos(&s_file_infos);
    printf("\033[1mDisplay all informations of the file :\n\033[0m");
    display_globals_attributes(&s_file_infos);
    display_dimensions(&s_file_infos);
    display_variables(&s_file_infos, ((argc > 2) ? true : false));
    close_file(s_file_infos.i_file_id);
}
