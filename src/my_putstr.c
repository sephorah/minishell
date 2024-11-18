/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** Day 04 - Task 02 - my_putstr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0'){
        my_putchar(*str);
        str += 1;
    }
    return 0;
}
