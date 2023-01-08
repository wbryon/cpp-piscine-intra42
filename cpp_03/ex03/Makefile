NAME = DiamondTrap

CLANG = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $< -o $@ -g 

$(NAME): $(OBJS)
		 $(CLANG) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean all