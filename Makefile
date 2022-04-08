NAME 		= fdf
CC			= gcc
CFLAGS		= -g -Wextra -Wall -Werror
MAIN		= srcs/fdf_main.c
FILES		= srcs/fdf_parsing.c \
			  srcs/fdf_utils.c \
		      srcs/fdf_rendering.c \
			  srcs/fdf_map_init.c 
TEST_FILES	= test.c

all : $(NAME) 

$(NAME): libft
	$(CC) $(CFLAGS) $(MAIN) $(FILES) -lmlx libft/libft.a -framework OpenGL -framework Appkit -o $(NAME)

.PHONY: clean fclean re libft test

libft:
	cd libft && $(MAKE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

test: libft
	$(CC) $(CFLAGS) $(TEST_FILES) $(FILES) -lmlx libft/libft.a -framework OpenGL -framework Appkit -o test