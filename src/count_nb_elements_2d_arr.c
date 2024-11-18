/*
** EPITECH PROJECT, 2023
** count_nb_elements_2d_arr.c
** File description:
** Minishell2
*/

#include <stdlib.h>

int count_nb_elements_2d_arr(char **args)
{
    int nb_args;

    for (nb_args = 0; args[nb_args] != NULL; nb_args++);
    return nb_args;
}
