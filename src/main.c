/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** minishell1
*/

#include "minishell.h"

int main(int ac, char const *argv[], char *const env[])
{
    if (ac != 1){
        return ERROR;
    }
    return command_interpreter(env);
}
