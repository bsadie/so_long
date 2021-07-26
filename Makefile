.PHONY: all clean fclean re

CC = clang
CFLAGS= -Wall -Wextra -Werror -c

NAME = so_long

INCLUDES = so_long.h

SRCS = main.c input.c help.c




OBJS = $(SRCS:.c=.o)

sll: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) -o $(NAME) $(OBJS)

SRCS.O: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) $(SRCS)

b:
	$(CC) $(CFLAGS) -g $(SRCS)
	$(CC) -o test $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
