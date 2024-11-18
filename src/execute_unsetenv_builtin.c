/*
** EPITECH PROJECT, 2023
** execute_unsetenv_builtin.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

char **remove_var_unsetenv(char **env_copy, int line_nb)
{
    int nb_lines = count_elements_array(env_copy);
    char **new_env = malloc(sizeof(char *) * (nb_lines));
    int i = 0;
    int j = 0;

    while (i != line_nb){
        new_env[i] = my_strdup(env_copy[i]);
        i++;
    }
    j = i + 1;
    while (i < nb_lines - 1 && j < nb_lines){
        new_env[i] = my_strdup(env_copy[j]);
        i++;
        j++;
    }
    new_env[i] = NULL;
    return new_env;
}

char **check_var_unsetenv(char *var, char **env_copy)
{
    int len_var = my_strlen(var);
    int nb_line_var = -1;
    char **new_env;

    for (int i = 0; env_copy[i] != NULL; i++){
        if (my_strncmp(var, env_copy[i], len_var) == 0){
            nb_line_var = i;
            break;
        }
    }
    if (nb_line_var > 0){
        new_env = remove_var_unsetenv(env_copy, nb_line_var);
        return new_env;
    }
    return env_copy;
}

char **execute_unsetenv_builtin(char **args, char **env_copy)
{
    int nb_args = count_elements_array(args);
    char **new_env = env_copy;

    if (nb_args >= 2){
        for (int i = 1; i < nb_args; i++){
            new_env = check_var_unsetenv(args[i], new_env);
        }
        return new_env;
    } else {
        my_print_error("unsetenv: Too few arguments.\n");
    }
    return env_copy;
}
