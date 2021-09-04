NAME = minishell

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES = minishell.c \
		minishell_utils1.c \
		minishell_utils2.c \
		minishell_utils3.c \
		minishell_utils4.c \
		minishell_utils5.c \
		parsing_main.c \
		parsing_one.c \
		parsing_two.c \
		parsing_three.c \
		command_one.c \
		command_two.c \
		command_three.c \
		minishell_var_one.c \
		minishell_var_two.c \
		parsing_command.c \
		ft_itoa.c \
		pipe_one.c \
		pipe_two.c \
		define_fd.c \
		define_path.c \
		parcing_redirect.c \
		ft_atoi.c

OBJS = $(FILES:%.c=%.o)

%.o: %.c minishell.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -lreadline

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re
