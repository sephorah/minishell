/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** Day 07 - Task 02 - my_strcat
*/

#include "minishell.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0'){
        dest[dest_len + i] = src[i];
        i += 1;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
