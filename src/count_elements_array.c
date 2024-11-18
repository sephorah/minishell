/*
** EPITECH PROJECT, 2023
** count_elements_array.c
** File description:
** minishell1
*/

#include <stdlib.h>

int count_elements_array(char **arr)
{
    int nb_elements;

    for (nb_elements = 0; arr[nb_elements] != NULL; nb_elements++);
    return nb_elements;
}
