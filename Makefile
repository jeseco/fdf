NAME 	= fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror

all : main 

main: libft libftprintf
	$(CC) $(CFLAGS) main.c libft/libft.a libft/libftprintf/libftprintf.a fdf_utils.c mlx/libmlx.a  -lmlx -framework Opengl -framework AppKit -L mlx -o $(NAME)

libft:
	cd libft && $(MAKE)

libftprintf:
	cd libft/libftprintf && $(MAKE)

PHONY.: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all