/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/06 15:54:34 by jcourtem         ###   ########.fr       */
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

	if (argc != 2)
		return (0);
	map = parsing(argv[1]);
	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, 1920, 1080, "fdf");
	img.image = mlx_new_image(mlx.server, 1920, 1080);
	render(map, &mlx);
	mlx_key_hook(mlx.window, &handle_key_input, &mlx);
	mlx_loop(mlx.server);
	return (0);
}
