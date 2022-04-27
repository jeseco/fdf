/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/27 10:01:53 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <mlx.h>
#include <stdbool.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->x_size)
	{
		free(map->vertex[i]);
		i++;
	}
	free (map->vertex);
}

int	handle_key_input(int key, t_mlx *mlx)
{
	if (key == ESC_KEY || key == 17)
	{
		free (mlx->image);
		mlx_destroy_image(mlx->server, mlx->image->image);
		mlx_destroy_window(mlx->server, mlx->window);
	}
	exit (0);
}

bool	correct_ext(char *path)
{
	while (*path != '\0')
	{
		while (*path != '.' && *path != '\0')
			path++;
		if (*path == '.')
			if (!ft_strncmp(path, ".fdf", 4))
				return (true);
		if (*path != '\0')
			path++;
	}
	return (false);
}

t_data	*init_img(t_mlx *mlx)
{
	t_data	*img;

	img = ft_calloc(1, sizeof(t_data));
	img->image = mlx_new_image(mlx->server, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	return (img);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	int		fd;

	if (argc != 2)
		return (0);
	if (!(correct_ext(argv[1])))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (0);
	map = parsing(fd);
	close(fd);
	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, WIDTH, HEIGHT, "fdf");
	mlx.image = init_img(&mlx);
	render(map, &mlx);
	free_map(&map);
	mlx_hook(mlx.window, 2, 3, &handle_key_input, &mlx);
	mlx_hook(mlx.window, 17, 0, &handle_key_input, &mlx);
	mlx_loop(mlx.server);
	return (0);
}
	