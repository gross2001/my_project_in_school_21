NAME = container
CXX = clang++ -std=c++98 -pedantic
modern: CXX = clang++

CXXLAGS = -Wall -Wextra -Werror -fsanitize=address 
RM = rm -f

FILES = main.cpp
OBJS = $(FILES:%.cpp=%.o)

%.o: %.cpp %.hpp
	$(CXX) $(CXXLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CXX) $(CXXLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

modern: re


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re
