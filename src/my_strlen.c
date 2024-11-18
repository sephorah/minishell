/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** Day 04 - Task 03 - my_strlen
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0'){
        count += 1;
    }
    return count;
}
