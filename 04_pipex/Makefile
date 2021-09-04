CC = gcc
CFLAGS = -Wall -Wextra -Werror
src = ft_pipex.c
obj = $(src:.c=.o)
HEADER = $(ft_pipex.h)
NAME = pipex

all: $(NAME)

$(NAME): $(obj) $(HEADER)
	$(CC) $(CFLAGS) -o pipex $(obj)

.PHONY: all NAME clean fclean re

clean:
	rm -f $(obj)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all


