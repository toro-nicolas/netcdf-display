/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The file containing the dimensions functions
*/
/**
 * @file dimensions.c
 * @brief The file containing the dimensions functions
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

/**
 * @brief Display the dimensions of the file
 * @param in_ps_file_info The file information
 * @return <b>void</b>
 */
void display_dimensions(file_information_t *in_ps_file_info)
{
    int32_t i_nb_unlimdims = 0;
    int32_t *ai_unlimdimids = NULL;

    ERROR(nc_inq_unlimdims(in_ps_file_info->i_file_id, &i_nb_unlimdims, NULL));
    ai_unlimdimids = calloc(i_nb_unlimdims, sizeof(int32_t));
    ERROR(nc_inq_unlimdims(in_ps_file_info->i_file_id, &i_nb_unlimdims, ai_unlimdimids));
    printf("\n    " BOLD UNDERLINE "Dimensions: %d\n" RESET, in_ps_file_info->i_nb_dimensions);
    for (int i_dim = 0; i_dim < in_ps_file_info->i_nb_dimensions; i_dim++) {
        char ac_dim_name[NC_MAX_NAME + 1];
        size_t i_dim_len = 0;

        ERROR(nc_inq_dim(in_ps_file_info->i_file_id, i_dim, ac_dim_name, &i_dim_len));
        printf(BOLD "Dimension %d:\n" RESET, i_dim);
        printf("  - name = %s\n", ac_dim_name);
        printf("  - length = %zu\n", i_dim_len);
        for (int32_t i_index = 0; i_index < i_nb_unlimdims; i_index++) {
            if (ai_unlimdimids[i_index] == i_dim) {
                printf("  - Unlimited dimension\n");
                break;
            }
        }
    }
    free(ai_unlimdimids);
}