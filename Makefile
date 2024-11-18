##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC			= 		src/main.c					\
					src/my_putstr.c 			\
					src/command_interpreter.c 	\
					src/my_str_to_word_array.c 	\
					src/my_strlen.c 			\
					src/my_strcpy.c 			\
					src/my_strncmp.c 			\
					src/my_strcmp.c 			\
					src/my_strcat_paths.c 		\
					src/my_strdup.c 			\
					src/find_path_bin.c 		\
					src/my_print_error.c 		\
					src/copy_env.c 				\
					src/execute_builtins.c 		\
					src/execute_cd_builtin.c 	\
					src/count_elements_array.c 	\
					src/display_env.c 			\
					src/my_strcat.c 			\
					src/execute_setenv_builtin.c \
					src/execute_unsetenv_builtin.c \
					src/free_ressources.c 			\
					src/is_env_empty.c 				\
					src/check_args_setenv.c 		\
					src/go_to_previous_dir.c 		\
					src/go_backup_to_previous_dir.c \
					src/go_to_relative_path_oldpwd.c \
					src/check_command.c 			\
					src/handle_redirections.c \
					src/handle_errors_execution.c 	\
					src/create_binary_tree.c 		\
					src/traverse_binary_tree.c 		\
					src/count_nb_elements_2d_arr.c 	\

OBJ 		=		$(SRC:.c=.o)

NAME 		=	 	mysh

CPPFLAGS	=		-I include/

CFLAGS	=	-Wall -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	fclean clean all re
