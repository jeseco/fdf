LOG:

Now we need to fix the isometric rendering of the map unto the image. 

-------------------------------------------------------------------------------

2022-02-24: git commit = b3a0973cee753042541fe626bdaa4a117e3f1a51

Now that the main logic for every file is build, we need to test the program and see that everything works perfectly. 

First we need to fix the segfault. 

It happens because the value of x and y aren't reset after the calculation of the max value in fdf_rendering.c:iso().

The puspose of this function is the set the value of x_pos and y_pox for every item in the t_pixel **map to the corresponding coordonates needed to represent the map in a isometric fashion.

The problem that we encounter is that the y value is not reset to 0, which we fixed by adding a y = 0 before the while (y <= get_y(c_data)). This will reset the value of y for every row in the t_pixel matrix table.

but we still get a segfault. c_data is empty, freed by the function parsing_char_to_pixel when in the iso function.

- Sometime the segfault happens in the fdf_utils.c:my_mlx_pixel_put(), when  (unsigned int *)dst = color;

	This happens because dst is null even if the previous statement:
	`dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));`

	In this situation, data is a t_data *data argument passed to the function, which is supposed to be the image to put the pixel on.

	A simple fix to this situation was to use the mlx_pixel_put in draw_line instead of my_mlx_pixel_put. We now don't have any segfaults but the rendered result is not what is expected, everything is on the top of the screen.


git log : c120371ecc0c79c29c6ae6def008233a79410dc3
-------------------------------------------------------------------------------

2022-02-18: git commit = cfe3cb07f9fbfe4381a9941f978626389890e721

Now that the makefile works everytime we call it, it is time to fully clean the structure of the project and to fix the segfault that we receive from running it.

tracking the segfault: 

1. running lldb debbug in vscode. 
    last called stack : mlx_get_data_addr.

I fixed this bug before I needed to rebuild my vm, this as something to do with how the structure from mlx. 

Upon testing, we can see that there is a problem when trying to creat a new img.img with mlx_new_image.

It gets called with the following variable:
1. mlx.window, 
2. HEIGHT="1080", 
3. WIDTH="1920"

once in, it...: 
1. initialize a new t_img *img;
2. check if (xvar="mlx.window"->use_xshm)
	2.2. if yes, check if img = mlx_int_new_xshm_image(xvar, width, height,zPixmap)
	2.3. return (img);
3. else, return (mlx_int_new_image(xvar, widht, height, ZPixmap))

in our case, it will return false on 2 and go to 3.
In mlx_int_new_image, when the program hits img->image = XCreateImage(xvar->display, xvar->visual, xvar->depth, format, 0, img->data,width,height,32,0);, there is an error because the next statement, if (!img->image) is true and frees the image.

I got tired of looking for what is going on in a library that is probably, as stated in their own docs, poorly build. I gonna rebuild my one main to see.

AFter rebuilding the main file, I builded the logiv for the rendering file. 

git commit = b3a0973cee753042541fe626bdaa4a117e3f1a51
----------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

git commit = cfe3cb07f9fbfe4381a9941f978626389890e721.