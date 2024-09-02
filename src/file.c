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

void check_error(int error)
{
    if (error != 0) {
        fprintf(stderr, RED BOLD "Error:" RESET RED " %s\n" RESET, nc_strerror(error));
        exit(1);
    }
}

void open_file(char *str_path, int32_t i_mode, int32_t *pi_file_id)
{
    if (nc_open(str_path, i_mode, pi_file_id)) {
        char str_exe_path[PATH_MAX] = {0};
        bool b_subfolder = false;
        int32_t i_len = readlink("/proc/self/exe", str_exe_path, sizeof(str_exe_path) - 1);
        if (i_len == -1) {
            fprintf(stderr, RED BOLD "Error: " RESET RED " Cannot find grib_to_netcdf.py\n" RESET);
            exit(1);
        }
        for (int32_t i_index = i_len; i_index > -1; i_index--) {
            if (str_exe_path[i_index] != '/')
                str_exe_path[i_index] = '\0';
            else if (b_subfolder == false)
                b_subfolder = true;
            else
                break;
        }
        strcat(str_exe_path, "grib_to_netcdf.py");
        int32_t i_file_name_index = 0;
        for (int32_t i_index = 0; str_path[i_index] != 0; i_index++) {
            if (str_path[i_index] == '/')
                i_file_name_index = i_index + 1;
        }
        char *str_output = calloc(strlen(str_path + i_file_name_index) + 9, sizeof(char));
        strcat(str_output, "/tmp/");
        strcpy(str_output, str_path + i_file_name_index);
        strcat(str_output, ".nc");
        char *astr_convert_args[] = {"/usr/bin/python3", str_exe_path, str_path, str_output, NULL};
        int32_t i_status = 0;
        pid_t i_pid = fork();
        char **astr_env = environ;
        char *str_pwd = getcwd(NULL, 0);


        if (i_pid == -1) {
            fprintf(stderr, RED BOLD "Error:" RESET RED " Cannot execute grib_to_netcdf.py\n" RESET);
            exit(1);
        }
        if (i_pid == 0) {
            if (execve(astr_convert_args[0], astr_convert_args, astr_env) == -1) {
                fprintf(stderr, RED BOLD "Error: Convertion to GRIB:" RESET RED " %s\n" RESET, strerror(errno));
                exit(errno);
            }
            exit(0);
        }
        waitpid(i_pid, &i_status, 0);
        if (WIFSIGNALED(i_status))
            fprintf(stderr, RED BOLD "Error: Convertion to GRIB:" RESET RED " %s\n" RESET, strsignal(WTERMSIG(i_status)));
        if (i_status != 0)
            exit(WEXITSTATUS(i_status));
        check_error(nc_open(str_output, i_mode, pi_file_id));
    }
}

void get_infos(file_informations *in_ps_file_infos)
{
    check_error(nc_inq(in_ps_file_infos->i_file_id,
        &in_ps_file_infos->i_nb_dimensions, &in_ps_file_infos->i_nb_variables,
        &in_ps_file_infos->i_nb_attributes,
        &in_ps_file_infos->i_first_unlimited_dimensions_id));
}

void close_file(int32_t i_file_id)
{
    check_error(nc_close(i_file_id));
}
