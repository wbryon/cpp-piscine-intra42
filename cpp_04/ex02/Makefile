NAME = abstract

CLANG = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $< -o $@
$(NAME): $(OBJS)
		 $(CLANG) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: re clean fclean all