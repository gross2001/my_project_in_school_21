CC = gcc
CFLAGS = -Wall -Wextra -Werror
src = ft_so_long.c ft_list.c ft_so_long_utils.c ft_so_long_map.c ft_so_long_map_2.c ft_so_long_mlx.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c
HEADER = ft_so_long.h
obj = ${src:.c=.o}
NAME = so_long

all: $(NAME)

$(NAME): $(obj) $(HEADER)
	gcc -Wall -Werror -Wextra -I. -g ${obj} -lmlx -framework OpenGL -framework AppKit\
		-o ${NAME}
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@

.PHONY: all NAME clean fclean re

clean:
	rm -f $(obj)

fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all
