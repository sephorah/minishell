/*
** EPITECH PROJECT, 2023
** execute_cd_builtin.c
** File description:
** minishell1
*/

#include <errno.h>
#include <unistd.h>
#include "minishell.h"

char *get_home_var(char *const env_copy[])
{
    char *home_var = NULL;

    for (int i = 0; env_copy[i] != NULL; i++){
        if (my_strncmp("HOME=", env_copy[i], 5) == 0){
            home_var = env_copy[i];
            break;
        }
    }
    return home_var;
}

void go_to_homedir(char *const env_copy[])
{
    char *home_var = get_home_var(env_copy);
    int len_home_var = my_strlen(home_var);
    char home_path[len_home_var - 4];
    char cwd_path[256];
    int i;

    for (i = 0; i < len_home_var - 4; i++)
        home_path[i] = home_var[i + 5];
    home_path[i] = '\0';

    if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
        return;
    while (my_strcmp(cwd_path, home_path) != 0){
        chdir("..");
        if (getcwd(cwd_path, sizeof(cwd_path)) == NULL)
            return;
    }
}

int handle_errors_cd_builtin(int chdir_return_val, char *dir)
{
    if (chdir_return_val == -1){
        if (errno == ENOENT){
            my_print_error(dir);
            my_print_error(": No such file or directory.\n");
            return 1;
        }
        if (errno == ENOTDIR){
            my_print_error(dir);
            my_print_error(": Not a directory.\n");
            return 1;
        }
        if (errno == EACCES){
            my_print_error(dir);
            my_print_error(": Permission denied.\n");
        }
    }
    return 0;
}

void execute_cd_options(int nb_args, char **args, char ***env_copy)
{
    int chdir_return_val = 0;
    char old_pwd[256];

    if (getcwd(old_pwd, sizeof(old_pwd)) == NULL)
        return;
    if (nb_args == 1 || (nb_args == 2 && (my_strcmp(args[0], "cd") == 0
    && my_strcmp(args[1], "~") == 0))){
        go_to_homedir(*env_copy);
        *env_copy = update_oldpwd_path(*env_copy, old_pwd);
        return;
    }
    if (nb_args == 2 && (my_strcmp(args[0], "cd") == 0 &&
    my_strcmp(args[1], "-") == 0)){
        go_to_previous_dir(env_copy);
        return;
    }
    chdir_return_val = chdir(args[1]);
    if (handle_errors_cd_builtin(chdir_return_val, args[1]) == 0)
        *env_copy = update_oldpwd_path(*env_copy, old_pwd);
}

void execute_cd_builtin(char **args, char ***env_copy)
{
    int nb_args = count_elements_array(args);

    if (nb_args > 2){
        my_print_error("cd: Too many arguments.\n");
        return;
    }
    execute_cd_options(nb_args, args, env_copy);
}
