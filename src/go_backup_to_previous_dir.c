/*
** EPITECH PROJECT, 2023
** go_backup_to_previous_dir.c
** File description:
** Minishell1
*/

#include <unistd.h>
#include "minishell.h"

void go_backup_to_previous_dir(char *oldpwd)
{
    char cwd_path[256];

    if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
        return;
    while (my_strcmp(cwd_path, oldpwd) != 0){
        chdir("..");
        if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
            return;
    }
}
