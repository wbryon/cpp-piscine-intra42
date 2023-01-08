NAME	= megaphone

SRCS	= megaphone.cpp

OBJS	= ${SRCS:.cpp=.o}

CC		= clang++

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	  $(NAME)

%.o:	  %.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):  $(OBJS)
		  $(CC) $(OBJS) -o $(NAME)

clean:		
		  $(RM) $(OBJS)

fclean:	  clean
		  $(RM) $(NAME)
re:		  fclean all

.PHONY:	  all clean fclean re