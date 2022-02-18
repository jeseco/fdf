LOG:

2022-02-18: git commit = 617ebfd0438664a3a822c773202f5f8c4f316849

Today, I'm trying to fix the architecture of the program and its arborescence, so that it will compile on linux. 

I cannot see what is the problem, when I try to compile only with `gcc -Wextra -Wall -Werror -g srcs/fdf_utils.c srcs/fdf_main.c minilibc-linux/libmlx.a -lXext -Lx11 -lm -lx -o fdf` The output is: `/usr/bin/ld: /tmp/cc4QuDeB.o: in function main': /home/kali/Desktop/fdf/srcs/fdf_main.c:42: undefined reference to parsing_char_to_t_pixel collect2: error: ld returned 1 exit status`. I just have to had the fdf_parsing.c to the compilation command.

Now that this is fixed, it cannot find the reference to ft_atoi and gnl_strcat, both of which are libft function. I will had the libft/libft.a to the compilation command. 

And now it compiles with the command : 
`gcc -Wextra -Wall -Werror -g srcs/fdf_utils.c srcs/fdf_main.c srcs/fdf_parsing.c minilibx-linux/libmlx.a libft/libft.a -lXext -lX11 -lm -o fdf`

and what we have in the fdf/Makefile is : 
`$(CC) $(CFLAGS) $(FILES) minilibx-linux/libmlx.a -lXext -lX11 -lm -o $(NAME)`
with :
```
NAME 	= fdf
CC		= gcc
CFLAGS	= -g -Wextra -Wall -Werror
FILES	= srcs/fdf_main.c \
		  srcs/fdf_parsing.c \
		  srcs/fdf_utils.c
```

I doubt that fdf, will behave in anyway that it is supposed to now that we are working in a linux/kali environment instead of a mac/bigsur one.

at this point, this is unimportant to me, I mainly want it to compile and the makefile to work withouth any problems everytime we need it.

The problem to be fixed is that when make is called in the fdf (main project dir) it will not call the recursive make for the libft in its dependencies.
right now we have in our fdf_makefile: 
```
$(NAME): libft
	$(CC) $(CFLAGS) $(FILES) minilibx-linux/libmlx.a libft/libft.a -lXext -lX11 -lm -o $(NAME)

libft:
	cd libft && $(MAKE)
```

and we tried with, withouth success... :
```
libft:
    cd libft && make
```

trying to declare the recipe "libft" as .PHONY because we have a file name libft in the dir.
This works. The reason being that, when a file exist in the current dir or sub dir, if a recipe in the makefile as the same name, makefile may confuse the file for the recipe and believe it is up to date even when it is not, hence not running the recipe and missing dependencies. 

git commit = 