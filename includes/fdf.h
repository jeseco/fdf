
#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define RED 			0x00ff0000
# define GREY 			0x01808080
# define WIDTH 			1920
# define HEIGHT 		1080
# define ESC_KEY		53

typedef struct s_pixel {
	int	x;
	int	y;
	int	z;
	int	color;
}		t_pixel;

typedef struct s_mlx{
	void *server;
	void *window;
}		t_mlx;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

int	creat_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);
int absolute(int a);

#endif