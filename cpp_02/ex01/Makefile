NAME = a.out

CLANG = clang++ -Wall -Wextra -Werror

SRCS =	main.cpp \
		Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CLANG) -c $< -o $@

$(NAME): $(OBJS)
	$(CLANG) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all