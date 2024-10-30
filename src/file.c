/*
** SEAGNAL PROJECT, 2024
** netcdf-display
** File description:
** The file containing the file functions
*/
/**
 * @file file.c
 * @brief The file containing the file functions
 * @author Nicolas TORO
 */

#include "../include/nc_display.h"

extern char **environ;

/**
 * @brief Check if there is an error
 * @param in_i_error The error code
 * @param in_ac_file The file name
 * @param in_i_line The line number
 * @param in_ac_func The function name
 * @return <b>void</b>
 */
void check_error(int in_i_error, const char *in_ac_file,
                 const int in_i_line, const char *in_ac_func)
{
    if (in_i_error != 0) {
        fprintf(stderr, RED BOLD "ERROR:" RESET RED " %s:%d: %s\n" RESET, in_ac_file, in_i_line, in_ac_func);
        fprintf(stderr, RED BOLD "Error information:" RESET RED " %s\n" RESET, nc_strerror(in_i_error));
        exit(1);
    }
}

/**
 * @brief Open a NetCDF file or a GRIB file
 * @param in_str_path The file path
 * @param in_i_mode The mode to open the file
 * @param in_pi_file_id The file id
 * @return <b>void</b>
 */
void open_file(char *in_str_path, int32_t in_i_mode, int32_t *in_pi_file_id)
{
    if (nc_open(in_str_path, in_i_mode, in_pi_file_id)) {
        char ac_exe_path[PATH_MAX] = {0};
        int32_t i_len = readlink("/proc/self/exe", ac_exe_path, sizeof(ac_exe_path) - 1);
        if (i_len == -1) {
            fprintf(stderr, RED BOLD "Error: " RESET RED " Cannot find grib_to_netcdf.py\n" RESET);
            exit(1);
        }
        for (int32_t i_index = i_len; i_index > -1; i_index--) {
            if (ac_exe_path[i_index] != '/')
                ac_exe_path[i_index] = '\0';
            else
                break;
        }
        strcat(ac_exe_path, "grib_to_netcdf.py");
        int32_t i_file_name_index = 0;
        for (int32_t i_index = 0; in_str_path[i_index] != 0; i_index++) {
            if (in_str_path[i_index] == '/')
                i_file_name_index = i_index + 1;
        }
        char *str_output = calloc(strlen(in_str_path + i_file_name_index) + 9, sizeof(char));
        strcat(str_output, "/tmp/");
        strcpy(str_output, in_str_path + i_file_name_index);
        strcat(str_output, ".nc");
        char *astr_convert_args[] = {"/usr/bin/python3", ac_exe_path, in_str_path, str_output, NULL};
        int32_t i_status = 0;
        pid_t i_pid = fork();
        char **astr_env = environ;

        if (i_pid == -1) {
            fprintf(stderr, RED BOLD "Error:" RESET RED " Cannot execute grib_to_netcdf.py\n" RESET);
            exit(1);
        }
        if (i_pid == 0) {
            if (execve(astr_convert_args[0], astr_convert_args, astr_env) == -1) {
                fprintf(stderr, RED BOLD "Error: Conversion to GRIB:" RESET RED " %s\n" RESET, strerror(errno));
                exit(errno);
            }
            exit(0);
        }
        waitpid(i_pid, &i_status, 0);
        if (WIFSIGNALED(i_status))
            fprintf(stderr, RED BOLD "Error: Conversion to GRIB:" RESET RED " %s\n" RESET, strsignal(WTERMSIG(i_status)));
        if (i_status != 0)
            exit(WEXITSTATUS(i_status));
        ERROR(nc_open(str_output, in_i_mode, in_pi_file_id));
    }
}

/**
 * @brief Get the information of the file
 * @param in_ps_file_info The file information
 * @return <b>void</b>
 */
void get_info(file_information_t *in_ps_file_info)
{
    ERROR(nc_inq(in_ps_file_info->i_file_id,
        &in_ps_file_info->i_nb_dimensions, &in_ps_file_info->i_nb_variables,
        &in_ps_file_info->i_nb_attributes,
        &in_ps_file_info->i_first_unlimited_dimensions_id));
}

/**
 * @brief Close a file
 * @param in_i_file_id The file id
 * @return <b>void</b>
 */
void close_file(int32_t in_i_file_id)
{
    ERROR(nc_close(in_i_file_id));
}
