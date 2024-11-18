/*
** EPITECH PROJECT, 2023
** execute_setenv_builtin.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

char *set_var_without_value(char **args)
{
    int len_name_variable = my_strlen(args[1]);
    char *line = malloc(sizeof(char) * (len_name_variable + 2));

    my_strcpy(line, args[1]);
    my_strcat(line, "=");
    return line;
}

char *set_var(char **args)
{
    int len_name_variable = my_strlen(args[1]);
    int len_value = my_strlen(args[2]);
    char *line = malloc(sizeof(char) * (len_name_variable + len_value + 2));

    my_strcpy(line, args[1]);
    my_strcat(line, "=");
    my_strcat(line, args[2]);
    return line;
}

char **add_line_setenv(char **args, int nb_args, char **env_copy)
{
    int nb_lines = count_elements_array(env_copy);
    char **new_env = malloc(sizeof(char *) * (nb_lines + 2));
    int i;

    for (i = 0; i < nb_lines; i++){
        new_env[i] = my_strdup(env_copy[i]);
    }
    new_env[i] = (nb_args == 3) ? set_var(args) : set_var_without_value(args);
    new_env[i + 1] = NULL;
    return new_env;
}

char **check_var_setenv(char **args, int nb_args, char **env_copy)
{
    int len_var = my_strlen(args[1]);
    int nb_line_var = -1;
    char **new_env;

    if (check_args_setenv(args, nb_args) != 0){
        return env_copy;
    }
    for (int i = 0; env_copy[i] != NULL; i++){
        if (my_strncmp(args[1], env_copy[i], len_var) == 0){
            nb_line_var = i;
            break;
        }
    }
    if (nb_line_var > 0){
        env_copy[nb_line_var] = set_var(args);
        return env_copy;
    } else {
        new_env = add_line_setenv(args, nb_args, env_copy);
    }
    return new_env;
}

char **execute_setenv_builtin(char **args, char **env_copy)
{
    int nb_args = count_elements_array(args);

    if (nb_args == 1)
        display_env(env_copy);
    if (nb_args == 2 || nb_args == 3){
        return check_var_setenv(args, nb_args, env_copy);
    }
    if (nb_args > 3)
        my_print_error("setenv: Too many arguments.\n");
    return env_copy;
}
