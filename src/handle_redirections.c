/*
** EPITECH PROJECT, 2023
** handle_pipes_and_redirections.c
** File description:
** Minishell2
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void restore_stdin_and_stdout(int *saved_stdin_stdout)
{
    dup2(saved_stdin_stdout[0], STDIN_FILENO);
    dup2(saved_stdin_stdout[1], STDOUT_FILENO);
}

void handle_redirection_stdin(struct node_s *root)
{
    char **tab = my_str_to_word_array(root->right->value, " \n\t");
    int fd = open(tab[0], O_RDONLY);

    if (fd != -1){
        dup2(fd, STDIN_FILENO);
        close(fd);
        return;
    }
}

void handle_redirection_stdout(struct node_s *node, char *separator)
{
    char **tab = my_str_to_word_array(node->right->value, " \n\t");
    int fd;

    if (my_strcmp(separator, ">") == 0){
        fd = open(tab[0], O_RDWR | O_TRUNC | O_CREAT, 0644);
    }
    if (my_strcmp(separator, ">>") == 0){
        fd = open(tab[0], O_RDWR | O_APPEND | O_CREAT, 0644);
    }
    if (fd != -1){
        dup2(fd, STDOUT_FILENO);
        close(fd);
        return;
    }
}

void handle_redirections(struct node_s *node, char *separator)
{
    if (my_strcmp(separator, ">") == 0 || my_strcmp(separator, ">>") == 0){
        handle_redirection_stdout(node, separator);
    }
    if (my_strcmp(separator, "<") == 0){
        handle_redirection_stdin(node);
    }
}
