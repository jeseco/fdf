
// [ ] clean this shit! 

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

# define RED 			0x00ff0000
# define GREY 			0x01808080
# define WIDTH 			1920
# define HEIGHT 		1080
# define ESC_KEY		53

typedef struct s_pixel {
	int	x_pos;
	int	y_pos;
	int	z_pos;
}		t_pixel;

typedef struct s_mlx{
	t_xvar *server;
	void *window;
}		t_mlx;

typedef struct s_data {
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

// function definitions:

// 		from fdf_utils: 
int		creat_trgb(int t, int r, int g, int b);

int		get_t(int trgb);

int		get_r(int trgb);

int 	get_g(int trgb);

int 	get_b(int trgb);

int 	absolute(int a);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		get_x(char *c_data);

int 	get_y(char *c_data);

t_pixel	**parsing_char_to_pixel(char *str);

void	draw_line(t_data *img, t_pixel start, t_pixel end);

void 	render(char *str, t_mlx mlx);

#endif