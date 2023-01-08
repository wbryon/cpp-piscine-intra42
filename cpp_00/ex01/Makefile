NAME =		phonebook

SRCS =		main.cpp \
			contact.cpp \
			phonebook.cpp

OBJS =		$(SRCS:%.cpp=%.o)

CFLAGS =	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			clang++ $(CFLAGS) -o $(NAME) $(SRCS)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all