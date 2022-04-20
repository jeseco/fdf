/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/20 14:48:49 by jcourtem         ###   ########.fr       */
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
	if (key == ESC_KEY)
	{
		mlx_destroy_image(mlx->server, mlx->image);
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
	if (map.error)
		return (0);
	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, 2560, 1440, "fdf");
	mlx.image = mlx_new_image(mlx.server, 2560, 1440);
	render(map, &mlx);
	free_map(&map);
	mlx_hook(mlx.window, 2, 3, &handle_key_input, &mlx);
	mlx_loop(mlx.server);
	return (0);
}
