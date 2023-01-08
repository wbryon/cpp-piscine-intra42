NAME = realType

CLANG = clang++ -Wall -Werror

SRC =	Base.cpp A.cpp B.cpp C.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CLANG) -c $< -o $@

$(NAME): $(OBJ)
	$(CLANG) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all