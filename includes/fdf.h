
#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

# define RED 			0x00ff0000
# define GREY 			0x01808080
# define WIDTH 			1920
# define HEIGHT 		1080
# define ESC_KEY		53

typedef struct s_pixel {
	int	x_pos;
	int	y_pos;
	int	z_pos;
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

int		creat_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int 	get_g(int trgb);
int 	get_b(int trgb);
int 	absolute(int a);
int		get_x(char *c_data);
int 	get_y(char *c_data);
void	draw_line(void *img, t_pixel start, t_pixel end, int color);
t_pixel	**parsing_char_to_t_pixel(int fd);

#endif