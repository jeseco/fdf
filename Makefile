NAME 	= fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror
FILES	= srcs/fdf_main.c \
		  srcs/fdf_rendering.c \
		  srcs/fdf_parsing.c \
		  srcs/fdf_draw_line.c \
		  srcs/fdf_utils.c 

.PHONY: clean fclean re libft test

all : $(NAME) 

$(NAME): libft
	$(CC) $(CFLAGS) $(FILES) minilibx-linux/libmlx.a libft/libft.a -lXext -lX11 -lm -o $(NAME)

libft:
	cd libft && $(MAKE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

test:
	gcc test/test_main.c $(FILES) ../minilibx-linux/libmlx_Linux.a ../srcs/fdf_parsing.c -Lmlx_linux -L/usr/lib -Imx_LlInux -lXext -lX11 -lm -lz 