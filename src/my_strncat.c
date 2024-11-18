/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** my_strncat
*/

#include "minishell.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < nb){
        dest[dest_len + i] = src[i];
        i += 1;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
