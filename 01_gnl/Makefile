CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10
src = get_next_line.c  get_next_line_utils.c  main.c
obj = $(src:.c=.o)
HEADER = get_next_line.h
NAME = run_gnl

all: $(NAME)

$(NAME): $(obj) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(obj)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -o $@ -c $<

.PHONY: all bonus clean fclean re

clean:
	rm -f $(obj)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all


