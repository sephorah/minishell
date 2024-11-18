/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** Day 07 - Task 02 - my_strcat
*/

#include "minishell.h"

char *my_strcat_paths(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src) + 1;
    int i = 0;

    dest[dest_len] = '/';
    while (i < src_len){
        dest[dest_len + i + 1] = src[i];
        i += 1;
    }
    return dest;
}
