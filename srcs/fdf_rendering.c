/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:13:24 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/06 16:37:49 by jcourtem         ###   ########.fr       */
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

void	update_coor(t_vertex *line, int dx, int dy, int *p)
{
	if (*p > 0)
	{
		*p += 2 * dy - 2 * dx;
		if (line[0].x_pos < line[1].x_pos)
			line[0].x_pos++;
		else
			line[0].x_pos--;
		if (line[0].y_pos < line[1].y_pos)
			line[0].y_pos++;
		else
			line[0].y_pos--;
	}
	else if (*p < 0)
	{
		*p += 2 * dy;
		if (line[0].x_pos < line[1].x_pos)
			line[0].x_pos++;
		else
			line[0].x_pos--;
	}
}

void	draw_line(t_vertex start, t_vertex end, t_mlx *mlx)
{
	int			dx;
	int			dy;
	int			p;
	t_vertex	line[2];

	dx = absolute(end.x_pos - start.x_pos);
	dy = absolute(end.y_pos - start.y_pos);
	p = 2 * dy - dx;
	line[0] = start;
	line[1] = end;
	while (!(same_coor(line[0], line[1])))
	{
		mlx_pixel_put(mlx->server, mlx->window, start.x_pos, start.y_pos, RED);
		update_coor(line, dx, dy, &p);
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
				draw_line(map.vertex[x][y], map.vertex[x - 1][y], mlx);
			draw_line(map.vertex[x][y], map.vertex[x][y + 1], mlx);
			y++;
			if (x != 0 && y != 0)
				draw_line(map.vertex[x][y], map.vertex[x -1][y], mlx);
		}
		x++;
	}
}
