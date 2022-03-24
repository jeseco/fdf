NAME 	= fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror
FILES	= srcs/fdf_main.c \
		  srcs/fdf_parsing.c \
		  srcs/fdf_utils.c 
#		  srcs/fdf_rendering.c \
		  srcs/fdf_draw_line.c \

.PHONY: clean fclean re libft test

all : $(NAME) 

$(NAME): libft
	$(CC) $(CFLAGS) $(FILES) -lmlx libft/libft.a -framework OpenGL -framework Appkit -o $(NAME)

libft:
	cd libft && $(MAKE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all