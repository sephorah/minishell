/*
** EPITECH PROJECT, 2023
** handle_errors_execution.c
** File description:
** Minishell2
*/

#include "errno.h"
#include "minishell.h"

void handle_errors_execution(int execve_return_value, char *path_bin)
{
    if (execve_return_value == -1 && errno == ENOEXEC){
        my_print_error(path_bin);
        my_print_error(": Exec format error. Wrong Architecture.\n");
    }
    if (execve_return_value == -1 && errno == EACCES){
        my_print_error(path_bin);
        my_print_error(": Permission denied.\n");
    }
}
