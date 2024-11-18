/*
** EPITECH PROJECT, 2023
** command_interpreter.c
** File description:
** mysh
*/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void display_prompt(void)
{
    if (isatty(0) == 1)
        my_putstr("$> ");
}

void catch_signals(int *wstatus)
{
    if (WIFSIGNALED(*wstatus)){
        if (WTERMSIG(*wstatus) == SIGSEGV && WCOREDUMP(*wstatus)){
            my_print_error("Segmentation fault (core dumped)\n");
            return;
        }
        if (WTERMSIG(*wstatus) == SIGSEGV){
            my_print_error("Segmentation fault\n");
        }
        if (WTERMSIG(*wstatus) == SIGFPE && SIGFPE){
            my_print_error("Floating exception (core dumped)\n");
            return;
        }
        if (WTERMSIG(*wstatus) == SIGFPE){
            my_print_error("Floating exception\n");
        }
    }
}

void execute_command(char *path_bin, char **args, char **env_copy[])
{
    pid_t pid_child = 0;
    int wstatus = 0;
    int execve_return_value;

    if (execute_builtins(args, env_copy) == 1)
        return;
    pid_child = fork();
    if (pid_child == 0){
        execve_return_value = execve(path_bin, args, *env_copy);
        handle_errors_execution(execve_return_value, path_bin);
    }
    waitpid(pid_child, &wstatus, 0);
    catch_signals(&wstatus);
}

void get_command(char *line, char **args, char **env_copy[])
{
    char *path_bin = find_path_bin(args[0], *env_copy);

    if (access(args[0], X_OK) == 0){
        execute_command(args[0], args, env_copy);
        return;
    }
    if (my_strcmp(path_bin, "none") == 0){
        my_print_error(args[0]);
        my_print_error(": Command not found.\n");
    } else {
        check_command(line, env_copy);
    }
}

int command_interpreter(char *const env[])
{
    size_t len = 0;
    char *line = NULL;
    char **args = NULL;
    char **env_copy = copy_env(env);

    is_env_empty(&env_copy);
    display_prompt();
    while (getline(&line, &len, stdin) != -1){
        args = my_str_to_word_array(line, " \n\t");
        if (args[0] != NULL)
            get_command(line, args, &env_copy);
        display_prompt();
    }
    free_ressources(line, args, env_copy);
    return SUCCESS;
}
