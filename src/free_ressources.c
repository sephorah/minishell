/*
** EPITECH PROJECT, 2023
** free_ressources.c
** File description:
** Minishell1
*/

#include <stdlib.h>

void free_ressources(char *line, char **args, char **env_copy)
{
    if (line != NULL)
        free(line);
    if (args != NULL)
        free(args);
    if (env_copy != NULL){
        for (int i = 0; env_copy[i] != NULL; i++){
            free(env_copy[i]);
        }
        free(env_copy);
    }
}
