/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** Day 08 - Task 01 - my_strdup
*/

#include <stdlib.h>
#include "minishell.h"

char *my_strdup(char const *src)
{
    char *str;
    int src_len = my_strlen(src);
    int i;

    str = malloc(sizeof(char) * (src_len + 1));
    i = 0;
    while (src[i] != '\0'){
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return str;
}
