NAME 	= libft.a

SRCS	= ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c \
 			ft_strlen.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_memset.c \
 			ft_bzero.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_itoa.c ft_calloc.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
 			ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
 			ft_putnbr_fd.c

SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c

OBJS 	= ${SRCS:.c=.o}

OBJS_B 	= ${SRCS_B:.c=.o}

CC		= gcc

CFLAGS 	= -Wall -Werror -Wextra 

RM		= rm -f

ARRC	= ar rc

${NAME}: ${OBJS}
		${ARRC} ${NAME} ${OBJS}

bonus:  ${OBJS_B}
		${ARRC} ${NAME} ${OBJS_B}

all: ${NAME}

so:
	$(CC) -fPIC $(CFLAGS) $(SRCS)
	$(CC)-shared -o libft.so $(OBJS)

clean: 
	${RM} ${OBJS} ${OBJS_B}


fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean
