/*
** EPITECH PROJECT, 2023
** check_command.c
** File description:
** Minishell
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int count_nb_separators_per_command(char **args_command)
{
    int nb_separators = 0;

    for (int i = 0; args_command[i] != NULL; i++){
        if (is_separator(args_command[i]))
            nb_separators += 1;
    }
    return nb_separators;
}

int is_separator(char *arg)
{
    if (my_strcmp(arg, ";") == 0)
        return 1;
    if (my_strcmp(arg, "|") == 0)
        return 1;
    if (my_strcmp(arg, ">") == 0)
        return 1;
    if (my_strcmp(arg, "<") == 0)
        return 1;
    if (my_strcmp(arg, ">>") == 0)
        return 1;
    if (my_strcmp(arg, "<<") == 0)
        return 1;
    return 0;
}

separator_t *create_separators_list(char **args, int nb_separators)
{
    separator_t *separators = (separator_t *)
    malloc(sizeof(separator_t) * (nb_separators + 1));
    int j = 0;

    for (int i = 0; args[i] != NULL; i++){
        if (is_separator(args[i])){
            separators[j].index = i;
            separators[j].separator = args[i];
            j += 1;
        }
    }
    separators[j].index = -1;
    separators[j].separator = NULL;
    return separators;
}

void check_command(char *line, char **env_copy[])
{
    int nb_separators;
    separator_t *separators;
    struct node_s *binary_tree;
    int p[2] = {STDIN_FILENO, STDOUT_FILENO};
    char **commands = my_str_to_word_array(line, ";");
    char **args_command;
    char *path_bin;

    for (int i = 0; commands[i] != NULL; i++){
        args_command = my_str_to_word_array(commands[i], " \n\t");
        nb_separators = count_nb_separators_per_command(args_command);
        if (nb_separators == 0){
            path_bin = find_path_bin(args_command[0], *env_copy);
            execute_command(path_bin, args_command, env_copy);
        } else {
            separators = create_separators_list(args_command, nb_separators);
            binary_tree = create_binary_tree(commands[i], separators);
            traverse_binary_tree(binary_tree, env_copy, p);
        }
    }
}
