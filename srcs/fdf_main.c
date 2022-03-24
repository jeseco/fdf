/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:58 by jcourtem          #+#    #+#             */
/*   Updated: 2022/03/24 14:07:07 by jcourtem         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_pixel	**map;

	if (argc != 2)
		return (0);
	map = parsing_char_to_pixel(argv[1]);
	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, WIDTH, HEIGHT, "fdf");
	// [ ] render(map, mlx):
	mlx_hook(mlx.window, 2, 1L<<0, &handle_key_input, &mlx);
	mlx_loop(mlx.server);
	return (0);
}