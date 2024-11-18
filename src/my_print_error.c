/*
** EPITECH PROJECT, 2023
** my_print_error.c
** File description:
** minishell1
*/

#include <unistd.h>
#include "minishell.h"

void my_print_error(char *str)
{
    char len_str = my_strlen(str);

    write(2, str, len_str);
}
