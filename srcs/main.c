/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/02/09 15:58:44 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <fcntl.h>

#include "../mlx/mlx.h"
#include "time.h"
#include "../includes/fdf.h"
#include "../includes/libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// clean this shit! 
void	draw_line(void *img, t_pixel start, t_pixel end, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = end.x_pos - start.x_pos;
	dy = end.y_pos - start.y_pos;
	if (absolute(dy) > absolute(dx))
	{	
		p = 2 * absolute(dy) - absolute(dx);
		while (start.y_pos != end.y_pos)
		{
			my_mlx_pixel_put(img, start.x_pos, start.x_pos, color);
			if (dy < 0)
				start.y_pos-- ;
			else
				start.y_pos++ ;
			if (p < 0)
				p = p + 2 * absolute(dx);
			else
			{
				p = p + (2 * absolute(dx)) - (2 * absolute(dy));
				if (dx < 0)
					start.x_pos-- ;
				else
					start.x_pos++ ;
			}
		}
	}
	else
	{	
		p = 2 * absolute(dx) - absolute(dy);
		while (start.x_pos != end.x_pos)
		{
			my_mlx_pixel_put(img, start.x_pos, start.x_pos, color);
			if (dx < 0)
				start.x_pos-- ;
			else
				start.x_pos++ ;
			if (p < 0)
				p = p + 2 * absolute(dy);
			else
			{
				p = p + (2 * absolute(dy)) - (2 * absolute(dx));
				if (dx < 0)
					start.y_pos-- ;
				else
					start.y_pos++ ;
			}
		}
	}
}

int key_press(int key, t_mlx *mlx)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window(mlx->server, mlx->window);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_data	img;
	t_pixel	**map;
	int		fd;

	// variable for put_map
	int	x = 0;
	int y = 0;

	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, HEIGHT, WIDTH, "window");
	img.img = mlx_new_image(mlx.window, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (argc <= 1)
	{
		ft_printf("ERROR: fdf requires a minimum of 1 arguments.\n");
		exit (EXIT_SUCCESS);
	}
	fd = open(argv[1], O_RDWR);
	map = parsing_char_to_t_pixel(fd);
	while (x <= 10)
	{
		while (y <= 10)
		{
			if (y < 10)
				draw_line(&img, map[x][y], map[x][y + 1], GREY);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx.server, mlx.window, img.img, 0, 0);
	mlx_hook(mlx.window, 2, 0x1L, &key_press, &mlx);
	mlx_loop(mlx.server);
	return (0);
}
