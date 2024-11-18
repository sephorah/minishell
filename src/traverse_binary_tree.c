/*
** EPITECH PROJECT, 2023
** traverse_binary_tree.c
** File description:
** Minishell2
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include <stdio.h>

void redirect_stdin_to_read_end(int *pipefd)
{
    if (pipefd[0] != -1) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        close(pipefd[0]);
    }
}

void execute_command_bin_tree(char *command, char **env_copy[], int *pipefd)
{
    char **args_command = my_str_to_word_array(command, " \n\t");
    char *path_bin = find_path_bin(args_command[0], *env_copy);
    pid_t pid_child = 0;
    int wstatus = 0;
    int execve_return_value;

    if (my_strcmp(path_bin, "none") == 0 ||
    execute_builtins(args_command, env_copy) == 1){
        return;
    }
    pid_child = fork();
    if (pid_child == 0){
        dup2(pipefd[1], STDOUT_FILENO);
        execve_return_value = execve(path_bin, args_command, *env_copy);
        handle_errors_execution(execve_return_value, path_bin);
    }
    waitpid(pid_child, &wstatus, 0);
    catch_signals(&wstatus);
}

void traverse_binary_tree(struct node_s *root, char **env_copy[], int *pipefd)
{
    int p[2];
    int saved_stdin_stdout[2] = { dup(STDIN_FILENO), dup(STDOUT_FILENO) };

    if (root == NULL){
        return;
    }
    if (!is_separator(root->value)){
        execute_command_bin_tree(root->value, env_copy, pipefd);
    }
    handle_redirections(root, root->value);
    if (my_strcmp(root->value, "|") == 0){
        pipe(p);
        traverse_binary_tree(root->left, env_copy, p);
        redirect_stdin_to_read_end(p);
    } else {
        traverse_binary_tree(root->left, env_copy, pipefd);
    }
    traverse_binary_tree(root->right, env_copy, pipefd);
    restore_stdin_and_stdout(saved_stdin_stdout);
}
