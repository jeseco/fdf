/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/08 11:55:59 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [ ] clean 
#include <time.h>
#include <mlx.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"

int	handle_key_input(int key, t_mlx *mlx)
{
	if (key == ESC_KEY)
		mlx_destroy_image(mlx->server, mlx->window);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	t_data	img;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (0);
	map = parsing(fd);
	close(fd);
	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, 2560, 1440, "fdf");
	img.image = mlx_new_image(mlx.server, 2560, 1440);
	render(map, &mlx);
	mlx_key_hook(mlx.window, &handle_key_input, &mlx);
	mlx_loop(mlx.server);
	return (0);
}
