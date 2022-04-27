/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:13:24 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/27 10:01:21 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	same_coor(t_vertex start, t_vertex end)
{
	if (start.x_pos != end.x_pos)
		return (0);
	if (start.y_pos != end.y_pos)
		return (0);
	return (1);
}

void	update_coor_y(t_vertex *start, t_vertex *end, int *d, int *p)
{
	if (*p > 0)
	{
		*p += 2 * d[0] - 2 * d[1];
		if (start->y_pos < end->y_pos)
			start->y_pos++;
		else
			start->y_pos--;
		if (start->x_pos < end->x_pos)
			start->x_pos++;
	else
			start->x_pos--;
	}
	else if (*p <= 0)
	{
		*p += 2 * d[0];
		if (start->y_pos < end->y_pos)
			start->y_pos++;
		else
			start->y_pos--;
	}
}

void	update_coor_x(t_vertex *start, t_vertex *end, int *d, int *p)
{
	if (*p > 0)
	{
		*p += 2 * d[1] - 2 * d[0];
		if (start->x_pos < end->x_pos)
			start->x_pos++;
		else
			start->x_pos--;
		if (start->y_pos < end->y_pos)
			start->y_pos++;
		else
			start->y_pos--;
	}
	else if (*p <= 0)
	{
		*p += 2 * d[1];
		if (start->x_pos < end->x_pos)
			start->x_pos++;
		else
			start->x_pos--;
	}
}

void	draw_line(t_vertex start, t_vertex end, t_data *img, t_map map)
{
	int	d[2];
	int	p;

	start.y_pos -= start.z_pos * (map.base);
	end.y_pos -= end.z_pos * (map.base);
	d[0] = absolute(end.x_pos - start.x_pos);
	d[1] = absolute(end.y_pos - start.y_pos);
	p = 2 * d[1] - d[0];
	while (!(same_coor(start, end)))
	{
		my_mlx_pixel_put(img, start.x_pos, start.y_pos, RED);
		if (d[0] > d[1])
			update_coor_x(&start, &end, d, &p);
		else
			update_coor_y(&start, &end, d, &p);
	}
}

void	render(t_map map, t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < map.x_size)
	{
		y = 0;
		while (y + 1 < map.y_size)
		{
			if (x != 0 && y == 0)
				draw_line(map.vertex[x][y], map.vertex[x - 1][y],
					mlx->image, map);
			draw_line(map.vertex[x][y], map.vertex[x][y + 1], mlx->image, map);
			y++;
			if (x != 0 && y != 0)
				draw_line(map.vertex[x][y], map.vertex[x -1][y],
					mlx->image, map);
		}
		x++;
	}
	mlx_put_image_to_window(mlx->server, mlx->window, mlx->image->image, 0, 0);
}
