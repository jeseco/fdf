/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:13:24 by jcourtem          #+#    #+#             */
/*   Updated: 2022/03/30 14:19:40 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	draw_line(t_mlx *mlx, t_vertex start, t_vertex end)
{
	int	dx;
	int	dy;
	int	p;

	dx = end.x_pos - start.x_pos;
	dy = end.y_pos - start.y_pos;
	if (absolute(dy) > absolute(dx))
	{	
		p = 2 * absolute(dy) - absolute(dx);
		while (start.y_pos != end.y_pos)
		{
			mlx_pixel_put(mlx->server, mlx->window, start.x_pos, start.y_pos, RED);
			if (dy < 0)
				start.y_pos-- ;
			else
				start.y_pos++ ;
			if (p < 0)
				p = p + 2 * absolute(dx);
			else
			{
				p = p + (2 * absolute(dx)) - (2 * absolute(dy));
				if (dx < 0)
					start.x_pos-- ;
				else
					start.x_pos++ ;
			}
		}
	}
	else
	{	
		p = 2 * absolute(dx) - absolute(dy);
		while (start.x_pos != end.x_pos)
		{
			mlx_pixel_put(mlx->server, mlx->window, start.x_pos, start.y_pos, RED);
			if (dx < 0)
				start.x_pos-- ;
			else
				start.x_pos++ ;
			if (p < 0)
				p = p + 2 * absolute(dy);
			else
			{
				p = p + (2 * absolute(dy)) - (2 * absolute(dx));
				if (dx < 0)
					start.y_pos-- ;
				else
					start.y_pos++ ;
			}
		}
	}
}

void render(t_map map, t_mlx *mlx)
{   
    int x;
    int y;

    x = 0;
    while (x < map.x_size)
    {
        y = 0;
        while(y + 1 < map.y_size)
        {
            if (x != 0 && y == 0)
                draw_line(mlx, map.vertex[x][y], map.vertex[x - 1][y]);
            draw_line(mlx, map.vertex[x][y], map.vertex[x][y + 1]);
            y++;
            if (x != 0 && y != 0)
                draw_line(mlx, map.vertex[x][y], map.vertex[x -1][y]);
        }
        x++;
    }
}