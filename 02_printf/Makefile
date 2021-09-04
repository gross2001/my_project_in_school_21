CC = gcc
CFLAGS = -Wall -Wextra -Werror
src = conversion.c flags.c printf.c utils.c utils_put.c utils_put2.c main.c
obj = $(src:%.c=$(obj_dir)/%.o)
obj_dir = OBJ
HEADER = $(ft_printf.h)
NAME = printf

all: $(NAME)

$(NAME): $(obj) $(HEADER) $(obj_dir)
	$(CC) -o $(NAME) $(obj)

$(obj_dir):
	mkdir -p $(obj_dir)

$(obj_dir)/%.o: %.c $(HEADER) | $(obj_dir)
	$(CC) $(CFLAGS) -I. -c -o $@ $<

.PHONY: all bonus clean fclean re

clean:
	rm -f $(obj)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all


