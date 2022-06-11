CC = gcc
CFLAGS = -Wall -Wextra -Werror
src =  ft_casting.c ft_list.c ft_move.c ft_so_long.c ft_check_errors.c\
		ft_so_long_map_2.c ft_so_long_map.c ft_so_long_utils.c \
		ft_images_bckgr.c ft_images_load.c ft_images_push.c ft_images_stripe.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c\
		parser/parser.c parser/init.c parser/errors.c  parser/config_parser.c\
		parser/map_checker.c parser/map_checker_utils1.c parser/map_checker_utils2.c\
		parser/config_utils1.c  parser/utils2.c parser/utils1.c\
		parser/player.c parser/utils_get_clr.c\

HEADER = ft_so_long.h
OBJDIR = OBJ
obj = $(src:%.c=$(OBJDIR)/%.o)
NAME = cub3d

all: $(NAME)

$(NAME): $(obj) $(HEADER)
	$(MAKE) -C parser/libft
	gcc $(CFLAGS) -o $(NAME) $(obj) -L parser/libft -lft  -lmlx -framework OpenGL -framework AppKit


$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/gnl
	mkdir -p $(OBJDIR)/parser

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all NAME clean fclean re

clean:
	rm -r $(OBJDIR)

fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all
