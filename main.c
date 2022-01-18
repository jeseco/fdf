#include "minilibx/mlx.h"
#include "time.h"

#define RED 0x00ff0000

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

void	draw_line(void *img, int start_x, int start_y, int end_x, int end_y)
{
    int dx;
	int dy;
	int p;

	dx = end_x - start_x;
	dy = end_y - start_y;
	if ((unsigned int)dx < (unsigned int)dy)
	{	
		p = (2 * (unsigned int)dy) - (unsigned)dx;
		while (start_y != end_y)
		{
			my_mlx_pixel_put(img, start_x, start_y, RED);
			if (dy < 0)
				start_y-- ;
			else
				start_y++ ;
			if (p < 0)
				p = p + 2 * (unsigned int)dx;
			else
			{
				p = p + (2 * (unsigned int)dx) - (2 * (unsigned int)dy);
				if (dx < 0)
					start_x-- ;
				else
					start_x++ ;
			}
		}
	}
	else
	{
		p = (2 * (unsigned int)dx) - (unsigned)dy;
		while (start_x != end_x)
		{
			my_mlx_pixel_put(img, start_x, start_y, RED);
			if (dx < 0)
				start_x-- ;
			else
				start_x++ ;
			if (p < 0)
				p = p + 2 * (unsigned int)dy;
			else
			{
				p = p + (2 * (unsigned int)dy) - (2 * (unsigned int)dx);
				if (dy < 0)
					start_y-- ;
				else
					start_y++ ;
			}
		}
	}
	// [ ] check if dx > dy = p = 2 * dy - dx || dy > dx = p = 2 * dx - dy && search x, y++
}

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win= mlx_new_window(vars.mlx, 1920, 1080, "window");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// #1 vertical 
	draw_line(&img, 960, 440, 960, 640);
	// #2 horizontal
	draw_line(&img, 860, 540, 1060, 540);
	// #3 45 down
	draw_line(&img, 920, 500, 1000, 580);
	// #4 45 up 
	draw_line(&img, 1000, 500, 500, 250);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	return (0);
}