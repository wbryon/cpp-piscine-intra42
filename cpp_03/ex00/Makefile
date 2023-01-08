NAME = ClapTrap

CLANG = clang++ -Wall -Wextra -Werror

SRCS =	main.cpp \
		ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CLANG) -c $< -o $@

$(NAME): $(OBJS)
	$(CLANG) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean all