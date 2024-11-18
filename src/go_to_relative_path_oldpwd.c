/*
** EPITECH PROJECT, 2023
** go_to_relative_path_oldpwd.c
** File description:
** Minishell1
*/

#include <unistd.h>
#include "minishell.h"

void go_to_relative_path_oldpwd(char *oldpwd, int len_oldpwd, int start)
{
    int len_newpwd = len_oldpwd - start + 1;
    int i;
    char new_pwd_path[len_newpwd];
    char cwd_path[256];

    if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
        return;
    start += (my_strcmp(cwd_path, "/") == 0) ? 0 : 1;
    for (i = 0; i < len_newpwd && start + i < len_oldpwd; i++)
        new_pwd_path[i] = oldpwd[start + i];
    new_pwd_path[i] = '\0';
    chdir(new_pwd_path);
}
