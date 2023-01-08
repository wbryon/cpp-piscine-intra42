NAME = convert
CLANG = clang++
FLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

SRCS = Scalar.cpp main.cpp
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