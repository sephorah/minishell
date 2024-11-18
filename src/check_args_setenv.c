/*
** EPITECH PROJECT, 2022
** check_args_setenv.c
** File description:
** check_args_setenv.c
*/

#include "minishell.h"

int is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }
    return 0;
}

int is_alphanumeric(char c)
{
    if (c >= 'A' && c <= 'Z'){
        return 1;
    } else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
        return 1;
    }
    return 0;
}

int is_str_alphanumeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!is_alphanumeric(str[i]) && str[i] != '_'){
            return 0;
        }
    }
    return 1;
}

int check_args_setenv(char **args, int nb_args)
{
    if (!is_alpha(args[1][0])){
        my_print_error("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (!is_str_alphanumeric(args[1])){
        my_print_error("setenv: Variable name must contain "
        "alphanumeric characters.\n");
        return 1;
    }
    return 0;
}
