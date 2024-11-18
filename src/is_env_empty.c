/*
** EPITECH PROJECT, 2023
** is_env_empty.c
** File description:
** Minishell1
*/

#include <stdlib.h>
#include "minishell.h"

void is_env_empty(char ***env_copy)
{
    int nb_elements_arr = count_elements_array(*env_copy);
    char **default_env = malloc(sizeof(char *) * 2);

    default_env[0] = "PATH=/usr/bin:/bin";
    default_env[1] = NULL;
    if (nb_elements_arr == 0){
        *env_copy = default_env;
    }
}
