/*
** EPITECH PROJECT, 2023
** Header file
** File description:
** example
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define _GNU_SOURCE
    #define ERROR 84
    #define SUCCESS 0

typedef struct separator_s {
    int index;
    char *separator;
} separator_t;

struct node_s {
    char *value;
    struct node_s *left;
    struct node_s *right;
};

int my_putstr(char const *str);

int command_interpreter(char *const env[]);

char **my_str_to_word_array(char const *str, char const *delim);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

int my_strncmp(const char *s1, const char *s2, int n);

int my_strcmp(const char *s1, const char *s2);

char *my_strcat_paths(char *dest, char const *src);

char *my_strdup(char const *src);

char *find_path_bin(char *command, char *const env[]);

void my_print_error(char *str);

char *my_strdup(char const *src);

char **copy_env(char *const env[]);

void execute_command(char *path_bin, char **args, char **env_copy[]);

int execute_builtins(char **args, char ***env_copy);

void execute_cd_builtin(char **args, char ***env_copy);

char **execute_setenv_builtin(char **args, char **env_copy);

int count_elements_array(char **arr);

void display_env(char **env_copy);

char *my_strcat(char *dest, char const *src);

char **execute_unsetenv_builtin(char **args, char **env_copy);

void free_ressources(char *line, char **args, char **env_copy);

void is_env_empty(char ***env_copy);

int check_args_setenv(char **args, int nb_args);

void go_to_previous_dir(char ***env_copy);

char **update_oldpwd_path(char **env_copy, char *old_pwd);

void go_backup_to_previous_dir(char *oldpwd);

void go_to_relative_path_oldpwd(char *oldpwd_path, int len_oldpwd, int start);

void check_command(char *line, char **env_copy[]);

int is_separator(char *arg);

void handle_separators(char **args, separator_t *separators,
char **env_copy[]);

void restore_stdin_and_stdout(int *saved_stdin_stdout);

int count_nb_elements_2d_arr(char **args);

void handle_errors_execution(int execve_return_value, char *path_bin);

void redirect_stdin_to_read_end(int *pipefd);

void catch_signals(int *wstatus);

struct node_s *create_binary_tree(char *line, separator_t *separators);

void traverse_binary_tree(struct node_s *root, char **env_copy[], int *pipefd);

void handle_redirections(struct node_s *node, char *separator);

#endif
