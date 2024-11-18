/*
** EPITECH PROJECT, 2023
** copy_env.c
** File description:
** copy_env.c
*/

#include <stdlib.h>
#include "minishell.h"

char **copy_env(char *const env[])
{
    char **dup_arr;
    int nb_rows;
    int i;

    for (nb_rows = 0; env[nb_rows] != NULL; nb_rows++);
    dup_arr = malloc(sizeof(char*) * (nb_rows + 1));
    for (i = 0; env[i] != NULL; i++){
        dup_arr[i] = my_strdup(env[i]);
    }
    dup_arr[i] = NULL;
    return dup_arr;
}
