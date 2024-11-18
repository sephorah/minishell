/*
** EPITECH PROJECT, 2023
** find_path_bin.c
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char *get_path_var(char *const env[])
{
    char *path_var = NULL;

    for (int i = 0; env[i] != NULL; i++){
        if (my_strncmp("PATH=", env[i], 5) == 0){
            path_var = env[i];
            break;
        }
    }
    return path_var;
}

char *find_path_bin_env(char *command, char *const env[])
{
    char *path_var = get_path_var(env);
    char *path_bin;
    char **paths = my_str_to_word_array(path_var, ":=");
    int len_path_var = (path_var != NULL) ? my_strlen(path_var) : 0;
    int len_command = my_strlen(command);

    if (len_path_var == 0)
        return "none";
    path_bin = malloc(sizeof(char) * (len_path_var + len_command + 2));
    for (int i = 0; paths[i] != NULL; i++){
        my_strcpy(path_bin, paths[i]);
        my_strcat_paths(path_bin, command);
        if (access(path_bin, X_OK) == 0)
            return path_bin;
    }
    return "none";
}

char *find_path_bin_cwd(char *command)
{
    char *path_bin;
    char cwd_path[256];
    int len_cwd_path;
    int len_command = my_strlen(command);

    if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
        return "none";
    len_cwd_path = my_strlen(cwd_path);
    path_bin = malloc(sizeof(char) * (len_cwd_path + len_command + 2));
    my_strcpy(path_bin, cwd_path);
    my_strcat_paths(path_bin, command);
    if (access(path_bin, X_OK) == 0)
        return path_bin;
    return "none";
}

char *find_builtin(char *command)
{
    char builtins[5][9] = {"cd", "setenv", "unsetenv", "env", "exit"};
    char *res;
    char **args = my_str_to_word_array(command, " \n");

    for (int i = 0; i < 5; i++){
        if (my_strcmp(args[0], builtins[i]) == 0){
            res = my_strdup(builtins[i]);
            free(args);
            return res;
        }
    }
    free(args);
    return "none";
}

char *find_path_bin(char *command, char *const env[])
{
    char *path_bin_env = NULL;
    char *path_bin_cwd = NULL;
    char *builtin = NULL;

    builtin = find_builtin(command);
    if (my_strcmp(builtin, "none") != 0){
        return builtin;
    }
    path_bin_env = find_path_bin_env(command, env);
    path_bin_cwd = find_path_bin_cwd(command);
    if (my_strcmp(path_bin_env, "none") == 0 &&
    my_strcmp(path_bin_cwd, "none") != 0){
        return path_bin_cwd;
    } else if (my_strcmp(path_bin_cwd, "none") == 0 &&
    my_strcmp(path_bin_env, "none") != 0){
        return path_bin_env;
    } else {
        return "none";
    }
}
