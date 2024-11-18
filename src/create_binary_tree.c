/*
** EPITECH PROJECT, 2023
** create_binary_tree.c
** File description:
** Minishell2
*/

#include <stdlib.h>
#include "minishell.h"
#include <stdio.h>

struct node_s *create_node(char *command)
{
    struct node_s *new_node = malloc(sizeof(struct node_s));

    new_node->value = command;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int count_nb_separators(separator_t *separators)
{
    int nb_separators = 0;

    for (int i = 0; separators[i].index != -1; i++){
        nb_separators += 1;
    }
    return nb_separators;
}

char **create_tab_commands(char *line, separator_t *separators)
{
    char **args_binary_tree = my_str_to_word_array(line, ";|><");
    char **tab = NULL;
    int nb_args = count_nb_elements_2d_arr(args_binary_tree);
    int nb_elements_tab = nb_args + count_nb_separators(separators);
    int i;
    int j = 0;
    int k = 0;

    tab = malloc(sizeof(char *) * nb_elements_tab);
    for (i = 0; i < nb_elements_tab; i++){
        if (i % 2 == 0){
            tab[i] = my_strdup(args_binary_tree[j]);
            j += 1;
        } else {
            tab[i] = separators[k].separator;
            k += 1;
        }
    }
    tab[i] = NULL;
    return tab;
}

struct node_s *create_binary_tree(char *line, separator_t *separators)
{
    char **tab = create_tab_commands(line, separators);
    int nb_elements_tab = count_nb_elements_2d_arr(tab);
    struct node_s *root = create_node(tab[nb_elements_tab - 1]);
    struct node_s *tmp;
    int i = nb_elements_tab - 2;

    while (i >= 0){
        if (is_separator(tab[i])){
            tmp = create_node(tab[i]);
            tmp->right = root;
            root = tmp;
        } else {
            root->left = create_node(tab[i]);
        }
        i -= 1;
    }
    return root;
}
