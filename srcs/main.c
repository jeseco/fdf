/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/01/25 14:56:37 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <fcntl.h>

#include "mlx/mlx.h"
#include "time.h"
#include "includes/fdf.h"
#include "includes/libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(void *img, int start_x, int start_y, int end_x, int end_y, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = end_x - start_x;
	dy = end_y - start_y;
	if (absolute(dy) > absolute(dx))
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
				if (dx < 0)
					start_y-- ;
				else
					start_y++ ;
			}
		}
	}
}

void	show_grid(void *img, int color)
{
	int	i;

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
	int		fd;
	char	*gnl_rtn;

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
	gnl_rtn = get_next_line(fd);
	while (gnl_rtn != NULL)
	{
		ft_printf("%s", gnl_rtn);
		gnl_rtn = get_next_line(fd);
	}
	mlx_put_image_to_window(mlx.server, mlx.window, img.img, 0, 0);
	mlx_hook(mlx.window, 2, 0x1L, &key_press, &mlx);
	mlx_loop(mlx.server);
	return (0);
}
