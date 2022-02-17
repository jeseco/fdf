NAME 	= fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror
FILES	= srcs/main.c \
		  srcs/parsing.c \
		  srcs/fdf_utils \
		  srcs/fdf_main.c \
		  srcs/fdf_draw_line.c 

all : main 

main: libft libftprintf
	$(CC) $(CFLAGS) $(FILES) libft/libft.a libft/libftprintf/libftprintf.a srcs/fdf_utils.c mlx/libmlx.a  -lmlx -framework Opengl -framework AppKit -L mlx -o $(NAME)

libft:
	cd libft && $(MAKE)

libftprintf:
	cd libft/libftprintf && $(MAKE)

parsing:
	$(CC) $(CFLAGS) srcs/parsing.c libft/libft.a libft/get_next_line_utils.c -o parsing

PHONY.: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
