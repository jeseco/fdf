NAME 		= fdf
CC			= gcc
CFLAGS		= -Wextra -Wall -Werror -g
FILES		= srcs/fdf_parsing.c \
			  srcs/fdf_utils.c \
		      srcs/fdf_rendering.c \
			  srcs/fdf_main.c \
			  srcs/fdf_map_init.c 
OBJS		= $(FILES:.c=.o)
LIBFT		= libft/libft.a

all : $(NAME) 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(FILES) -lmlx $(LIBFT) -framework OpenGL -framework Appkit -o $(NAME)

$(LIBFT):
	cd libft && $(MAKE)

$(OBJS):

.PHONY: clean fclean re libft test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

test: libft
	$(CC) $(CFLAGS) $(TEST_FILES) $(FILES) -lmlx libft/libft.a -framework OpenGL -framework Appkit -o test