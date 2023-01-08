NAME   =	violence

SRCS   =	main.cpp \
			Weapon.cpp \
			HumanA.cpp \
			HumanB.cpp

OBJS   =	$(SRCS:%.cpp=%.o)

CC	   =	clang++

CFLAGS =	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all