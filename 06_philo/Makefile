CC = gcc
src_dir := mandatory
HEADER = $(mandatory/ft_philo.h)
CFLAGS = -Wall -Wextra -Werror -pthread
src = $(src_dir)/ft_philo.c $(src_dir)/ft_philo_libft.c $(src_dir)/ft_philo_utils.c \
		$(src_dir)/ft_philo_utils2.c $(src_dir)/ft_philo_thread.c
obj = $(src:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(obj) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(obj)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all NAME clean fclean re

clean:
	rm -f $(obj)

fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all
