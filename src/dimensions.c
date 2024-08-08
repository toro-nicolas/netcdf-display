/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file dimensions.cc
 * @brief The main file of the project
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

void display_dimensions(file_informations *in_ps_file_infos)
{
    int32_t i_nb_unlimdims = 0;
    int32_t *ai_unlimdimids = NULL;

    nc_inq_unlimdims(in_ps_file_infos->i_file_id, &i_nb_unlimdims, NULL);
    ai_unlimdimids = calloc(i_nb_unlimdims, sizeof(int32_t));
    nc_inq_unlimdims(in_ps_file_infos->i_file_id, &i_nb_unlimdims, ai_unlimdimids);
    printf("\n    \033[1m\033[4mDimensions: %d\n\033[0m", in_ps_file_infos->i_nb_dimensions);
    for (int i_dim = 0; i_dim < in_ps_file_infos->i_nb_dimensions; i_dim++) {
        char ac_dim_name[NC_MAX_NAME + 1];
        size_t i_dim_len = 0;

        check_error(nc_inq_dim(in_ps_file_infos->i_file_id, i_dim, ac_dim_name, &i_dim_len));
        printf("\033[1mDimension %d:\n\033[0m", i_dim);
        printf("  - name = %s\n", ac_dim_name);
        printf("  - lenght = %zu\n", i_dim_len);
        for (int32_t i_index = 0; i_index < i_nb_unlimdims; i_index++) {
            if (ai_unlimdimids[i_index] == i_dim) {
                printf("  - Unlimited dimension\n");
                break;
            }
        }
    }
    free(ai_unlimdimids);
}