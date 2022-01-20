#include "minilibx/mlx.h"
#include "time.h"
#include "fdf.h"

#define RED 	0x00ff0000
#define GREY 	0x01808080
#define WIDTH 	1920
#define HEIGHT 	1080

typedef	struct s_pixel {
	int x;
	int y;
	int z; 
	int color;
}	pixel;

typedef struct s_vars {
	void *mlx;
	void *win;
}		t_vars;

typedef struct s_data {
	void 	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	swap(int *i_1, int *i_2)
{
	void *temp;

	temp = i_1;
	i_1 = i_2;
	i_2 = temp;
}

void	draw_line(void *img, int start_x, int start_y, int end_x, int end_y, int color)
{
    int dx;
	int dy;
	int p;

	dx = end_x - start_x;
	dy = end_y - start_y;
	if (absolute(dx) < absolute(dy))
	{	
		p = 2 * absolute(dy) - absolute(dx);
		while (start_y != end_y)
		{
			my_mlx_pixel_put(img, start_x, start_y, color);
			if (dy < 0)
				start_y-- ;
			else
				start_y++ ;
			if (p < 0)
				p = p + 2 * absolute(dx);
			else
			{
				p = p + (2 * absolute(dx)) - (2 * absolute(dy));
				if (dx < 0)
					start_x-- ;
				else
					start_x++ ;
			}
		}
	}
	else
	{
		p = 2 * absolute(dx) - absolute(dy);
		while (start_x != end_x)
		{
			my_mlx_pixel_put(img, start_x, start_y, color);
			if (dx < 0)
				start_x-- ;
			else
				start_x++ ;
			if (p < 0)
				p = p + 2 * absolute(dy);
			else
			{
				p = p + (2 * absolute(dy)) - (2 * absolute(dx));
				if (dy < 0)
					start_y-- ;
				else
					start_y++ ;
			}
		}
	}
}

void	show_grid(void *img, int color)
{
	int i;

	i = 0;
	while (i <= WIDTH)
	{
		draw_line(img, i, 0, i, HEIGHT, color);
		i += 20;
	}
	i = 0;
	while (i <= HEIGHT)
	{
		draw_line(img, 0, i, WIDTH, i, color);
		i += 20;
	}
}

int main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win= mlx_new_window(vars.mlx, 1920, 1080, "window");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	show_grid(&img, GREY);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
