NAME 	= fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror
FILES	= srcs/fdf_main.c \
		  srcs/fdf_parsing.c \
		  srcs/fdf_utils.c

#srcs/fdf_draw_line.c 
#srcs/fdf_draw_map.c  

.PHONY: clean fclean re libft

all : $(NAME) 

$(NAME): libft
	$(CC) $(CFLAGS) $(FILES) minilibx-linux/libmlx.a libft/libft.a -lXext -lX11 -lm -o $(NAME)

libft:
	cd libft && $(MAKE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
