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

#include <stdio.h>
#include <fcntl.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_data	img;
	t_pixel	**map;
	int		fd;

	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, HEIGHT, WIDTH, "window");
	img.img = mlx_new_image(mlx.window, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (argc <= 1)
		exit (EXIT_SUCCESS);
	fd = open(argv[1], O_RDWR);
	map = parsing_char_to_t_pixel(fd);
	printf("map.1.1 = %i", map[1][1].x_pos);
	mlx_put_image_to_window(mlx.server, mlx.window, img.img, 0, 0);
	mlx_loop(mlx.server);
	return (0);
}
