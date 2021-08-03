.PHONY: all clean fclean re

CC = clang
CFLAGS= -Wall -Wextra -Werror -g

NAME = so_long

INCLUDES = so_long.h

SRCS = main.c					\
		actions.c				\
		action_hook.c			\
		input.c					\
		input2.c				\
		init_memory.c			\
		help.c					\
		check_args.c			\
		check_is_closed.c		\
		check_is_contents.c		\
		check_is_rectangular.c	\
		graphics.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)



#$(NAME): $(OBJS) $(INCLUDES)
#	$(CC) -o $(NAME) $(OBJS)

#SRCS.O: $(SRCS) $(INCLUDES)
#	$(CC) $(CFLAGS) $(SRCS)

b:
	$(CC) $(CFLAGS) -g $(SRCS)
	$(CC) -o test $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
