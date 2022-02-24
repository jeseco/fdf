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

// [ ] clean 

#include <stdio.h>
#include <fcntl.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"

int	main(int argc, char **argv)
{
	t_mlx 	mlx;

	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, HEIGHT, WIDTH, "FDF");
	if (argc <= 1)
		exit (EXIT_SUCCESS);
	render(argv[1], mlx);
	mlx_loop(mlx.server);
	return (0);
}
