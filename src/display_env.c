/*
** EPITECH PROJECT, 2023
** display_env.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include "minishell.h"

void display_env(char **env_copy)
{
    for (int i = 0; env_copy[i] != NULL; i++){
        my_putstr(env_copy[i]);
        my_putstr("\n");
    }
}
