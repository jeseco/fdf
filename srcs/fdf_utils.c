/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:35 by jcourtem          #+#    #+#             */
/*   Updated: 2022/02/09 15:46:32 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	creat_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return (trgb & 0xfFF);
}

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
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

// void	show_grid(void *img, int color)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= WIDTH)
// 	{
// 		draw_line(img, i, 0, i, HEIGHT, color);
// 		i += 20;
// 	}
// 	i = 0;
// 	while (i <= HEIGHT)
// 	{
// 		draw_line(img, 0, i, WIDTH, i, color);
// 		i += 20;
// 	}
// }