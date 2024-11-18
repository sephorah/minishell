/*
** EPITECH PROJECT, 2023
** execute_builtins.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int execute_pwd(char **args)
{
    char cwd_path[256];
    int nb_elements = count_elements_array(args);

    if (my_strcmp(args[0], "pwd") == 0 && nb_elements == 1){
        if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
            return 1;
        my_putstr(cwd_path);
        my_putstr("\n");
        return 1;
    }
    return 0;
}

int execute_builtins(char **args, char ***env_copy)
{
    if (my_strcmp(args[0], "cd") == 0){
        execute_cd_builtin(args, env_copy);
        return 1;
    } else if (my_strcmp(args[0], "setenv") == 0){
        *env_copy = execute_setenv_builtin(args, *env_copy);
        return 1;
    }
    if (my_strcmp(args[0], "unsetenv") == 0){
        *env_copy = execute_unsetenv_builtin(args, *env_copy);
        return 1;
    } else if (my_strcmp(args[0], "env") == 0){
        display_env(*env_copy);
        return 1;
    }
    if (my_strcmp(args[0], "exit") == 0){
        exit(SUCCESS);
        return 1;
    } else if (execute_pwd(args) == 1)
        return 1;
    return 0;
}
