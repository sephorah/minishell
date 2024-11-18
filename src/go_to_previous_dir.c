/*
** EPITECH PROJECT, 2023
** go_to_previous_dir.c
** File description:
** Minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char *create_oldpwd_line(char *pwd)
{
    int len_pwd = my_strlen(pwd);
    char *line = malloc(sizeof(char) * (len_pwd + 9));

    my_strcpy(line, "OLDPWD=");
    my_strcat(line, pwd);
    return line;
}

char **set_oldpwd_path(char **env_copy, char *pwd_path)
{
    int nb_lines = count_elements_array(env_copy);
    char **new_env = malloc(sizeof(char *) * (nb_lines + 2));
    int i;

    for (i = 0; i < nb_lines; i++){
        new_env[i] = my_strdup(env_copy[i]);
    }
    new_env[i] = create_oldpwd_line(pwd_path);
    new_env[i + 1] = NULL;
    return new_env;
}

char **update_oldpwd_path(char **env_copy, char *old_pwd)
{
    int nb_line_oldpwd = 0;
    char **new_env;

    for (int i = 0; env_copy[i] != NULL; i++){
        if (my_strncmp("OLDPWD=", env_copy[i], 7) == 0){
            nb_line_oldpwd = i;
            break;
        }
    }
    if (nb_line_oldpwd > 0){
        env_copy[nb_line_oldpwd] = create_oldpwd_line(old_pwd);
        return env_copy;
    } else {
        new_env = set_oldpwd_path(env_copy, old_pwd);
        return new_env;
    }
}

char *get_oldpwd_path(char **env_copy)
{
    char *oldpwd_var = NULL;
    char **arr;

    for (int i = 0; env_copy[i] != NULL; i++){
        if (my_strncmp("OLDPWD=", env_copy[i], 7) == 0){
            oldpwd_var = env_copy[i];
            break;
        }
    }
    if (oldpwd_var == NULL){
        return "error";
    }
    arr = my_str_to_word_array(oldpwd_var, "=");
    return arr[1];
}

void go_to_previous_dir(char ***env_copy)
{
    char *oldpwd_path = get_oldpwd_path(*env_copy);
    char cwd_path[256];
    int len_oldpwd;
    int i;

    if (my_strcmp(oldpwd_path, "error") == 0){
        my_print_error(": No such file or directory.\n");
        return;
    }
    if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
        return;
    for (i = 0; cwd_path[i] == oldpwd_path[i]; i++);
    len_oldpwd = my_strlen(oldpwd_path);
    if (i < len_oldpwd){
        go_to_relative_path_oldpwd(oldpwd_path, len_oldpwd, i);
    } else {
        go_backup_to_previous_dir(oldpwd_path);
    }
    *env_copy = update_oldpwd_path(*env_copy, cwd_path);
}
