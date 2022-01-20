NAME = fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror

all : main

main:
	$(CC) $(CFLAGS) main.c fdf_utils.c minilibx/libmlx.a -lmlx -lXext -lX11 -L minilibx -o $(NAME)

PHONY.: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all