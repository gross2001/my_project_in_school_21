CC = gcc
src_dir := mandatory
bonus_dir := bonus
HEADER = $(mandatory/ft_push_swap.h)
HEADER_BNS = $(bonus/ft_push_swap_bonus.h)
CFLAGS = -Wall -Wextra -Werror
src = $(src_dir)/ft_push_swap.c $(src_dir)/ft_algorithm.c $(src_dir)/ft_checkers.c $(src_dir)/ft_commands.c \
	  $(src_dir)/ft_list.c $(src_dir)/ft_utils.c $(src_dir)/ft_min_max_median.c
bns = $(src_dir)/ft_checkers.c $(src_dir)/ft_list.c $(src_dir)/ft_utils.c \
     	 $(bonus_dir)/ft_push_swap_bonus.c $(bonus_dir)/ft_commands_bonus.c \
      	$(bonus_dir)/ft_push_swap_bonus_utils.c $(bonus_dir)/gnl/get_next_line.c \
      	$(bonus_dir)/gnl/get_next_line_utils.c
obj = $(src:.c=.o)
bns_obj = $(bns:.c=.o)
NAME = push_swap
BONUS = checker

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(obj) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(obj)

$(BONUS): $(bns_obj) $(HEADER_BNS)
	$(CC) $(CFLAGS) -o $(BONUS) $(bns_obj)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all NAME bonus clean fclean re

clean:
	rm -f $(obj)
	rm -f $(bns_obj)

fclean:
	make clean
	rm -f $(NAME)
	rm -f checker
re:
	make fclean
	make all
