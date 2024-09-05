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

void display(settings_t *ps_settings)
{
    file_informations s_file_infos = {0};

    open_file(ps_settings->ac_file, NC_NOWRITE, &s_file_infos.i_file_id);
    get_infos(&s_file_infos);
    if (!ps_settings->b_variable && ps_settings->b_attribute)
        printf(BOLD "WARNING:" RESET " Variable attributes display is selectable, but variable display is not.\n");
    if (!ps_settings->b_variable && ps_settings->b_content)
        printf(BOLD "WARNING:" RESET " Variable content display is selectable, but variable display is not.\n");
    printf("\033[1mDisplay all informations of the file :\n\033[0m");
    if (ps_settings->b_global_attributes == false && ps_settings->b_dimension == false &&
    ps_settings->b_variable == false) {
        printf("\nNothing to show.\n");
        return;
    }
    if (ps_settings->b_global_attributes)
        display_globals_attributes(&s_file_infos);
    if (ps_settings->b_dimension)
        display_dimensions(&s_file_infos);
    if (ps_settings->b_variable)
        display_variables(&s_file_infos, ps_settings);
    close_file(s_file_infos.i_file_id);
}

int main(int argc, char **argv)
{
    int32_t c_flag = 0;
    int32_t i_option_index = 0;
    settings_t s_settings = {false, false, false, false, false, false, NULL};
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"switch", no_argument, 0, 's'},
        {"global-attributes", no_argument, 0, 'g'},
        {"dimensions", no_argument, 0, 'd'},
        {"variables", no_argument, 0, 'v'},
        {"attributes", no_argument, 0, 'a'},
        {"content", no_argument, 0, 'c'},
        {"raw", no_argument, 0, 'r'},
        {0, 0, 0, 0}
    };

    if (argc == 1) {
        fprintf(stderr, RED BOLD "%s:" RESET RED " No arguments passed\n" RESET, argv[0]);
        fprintf(stderr, BOLD "Usage:" RESET " %s file [OPTIONS] ...\n", argv[0]);
        fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
        return EXIT_FAILURE;
    }
    opterr = 0;
    while (1) {
        c_flag = getopt_long(argc, argv, "hsgdvacr", long_options, &i_option_index);
        if (c_flag == -1)
            break;
        switch (c_flag) {
            case 'h':
                printf(BOLD "Usage:" RESET " %s file [OPTIONS] ...\n\n", argv[0]);
                printf(BOLD UNDERLINE "DESCRIPTION\n" RESET);
                printf("\tDisplay the content of a NetCDF file.\n\n");
                printf(BOLD UNDERLINE "OPTIONS\n" RESET);
                printf("\t-h, --help\t\t\tDisplay this help and exit\n");
                printf("\t-s, --switch\t\t\tSwitch between all options\n");
                printf("\t-g, --global-attributes\t\tDisplay global attributes\n");
                printf("\t-d, --dimensions\t\t\tDisplay dimensions\n");
                printf("\t-v, --variables\t\t\tDisplay variables\n");
                printf("\t-a, --attributes\t\t\tDisplay attributes of variables\n");
                printf("\t-c, --content\t\t\tDisplay content of variables\n");
                printf("\t-r, --raw\t\t\tDisplay content of variables in a raw text\n");
                return EXIT_SUCCESS;
            case 's':
                s_settings.b_global_attributes = !s_settings.b_global_attributes;
                s_settings.b_dimension = !s_settings.b_dimension;
                s_settings.b_variable = !s_settings.b_variable;
                s_settings.b_attribute = !s_settings.b_attribute;
                s_settings.b_content = !s_settings.b_content;
                break;
            case 'g':
                s_settings.b_global_attributes = !s_settings.b_global_attributes;
                break;
            case 'd':
                s_settings.b_dimension = !s_settings.b_dimension;
                break;
            case 'v':
                s_settings.b_variable = !s_settings.b_variable;
                break;
            case 'a':
                s_settings.b_attribute = !s_settings.b_attribute;
                break;
            case 'c':
                s_settings.b_content = !s_settings.b_content;
                break;
            case 'r':
                s_settings.b_raw = !s_settings.b_raw;
                break;
            default:
                printf(BOLD "%s:" RESET " Unknown option '-%c'.\n", argv[0], optopt);
                return EXIT_FAILURE;
        }
    }
    if (optind < argc) {
        s_settings.ac_file = argv[optind];
        if (optind + 1 < argc) {
            printf(BOLD "%s:" RESET " Too many arguments.\n", argv[0]);
            return EXIT_FAILURE;
        }
    } else {
        printf(BOLD "%s:" RESET " File not provided.\n", argv[0]);
        return EXIT_FAILURE;
    }
    display(&s_settings);
    return EXIT_SUCCESS;
}
