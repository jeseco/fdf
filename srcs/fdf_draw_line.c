/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:39 by jcourtem          #+#    #+#             */
/*   Updated: 2022/02/09 13:29:49 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [ ] clean this shit! 

#include "../includes/fdf.h"

// void	draw_line(void *img, t_pixel p_start, t_pixel p_end)
// {
	
// }

void	draw_line(void *img, t_pixel start, t_pixel end, int color)
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
			my_mlx_pixel_put(img, start.x_pos, start.x_pos, color);
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
			my_mlx_pixel_put(img, start.x_pos, start.x_pos, color);
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