NAME 	= fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror
FILES	= srcs/fdf_main.c \
		  srcs/fdf_parsing.c \
		  srcs/fdf_utils

#srcs/fdf_draw_line.c 
#srcs/fdf_draw_map.c  

all : main 

main: libft 
	$(CC) $(CFLAGS) $(FILES) libft/libft.a minilibx-linux/libmlx.a $(FILES) -lXext -lX11 -lm -lx -o $(NAME)

libft:
	cd libft && make

libftprintf:
	cd libft/libftprintf && make

parsing:
	$(CC) $(CFLAGS) srcs/parsing.c libft/libft.a libft/get_next_line_utils.c -o parsing

PHONY.: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
