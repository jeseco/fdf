/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/03/30 14:35:18 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [ ] clean 
#include <time.h>


#include <mlx.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"

int handle_key_input(int key, t_mlx *mlx)
{
	if (key == ESC_KEY)
		mlx_destroy_image(mlx->server, mlx->window);
	return (0);
}

int	main(void /*int argc, char **argv*/)
{
	// t_map	map;
	t_mlx 	mlx;
	t_data	img;

	// if (argc != 2)
	// 	return (0);
	// map = parsing(argv[1]);
	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, 1920, 1080, "fdf");
	img.image = mlx_new_image(mlx.server, 1920, 1080);
	// render(map, &mlx);
	t_vertex p1 = {960, 10, 0, 0};
	t_vertex p2 = {1110, 110, 0, 0};
	t_vertex p3 = {810, 110, 0, 0};
	t_vertex p4 = {960, 210, 0, 0};
	
	draw_line(&mlx, p1, p2);
	// draw_line(&mlx, p3, p1);
	draw_line(&mlx, p3, p4);
	// draw_line(&mlx, p4, p2);
	mlx_key_hook(mlx.window, &handle_key_input, &mlx);
	mlx_loop(mlx.server);
	return (0);
}