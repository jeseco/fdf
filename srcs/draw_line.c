/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:39 by jcourtem          #+#    #+#             */
/*   Updated: 2022/02/02 11:15:19 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
1.
	if the absolute value of the differrence in x is smaller than the difference in y
		p equal twice the absolute difference in y minus the absolute difference in x
	else if the absolute difference in y is smaller than the diffrence in x
		p equal twice the absolute difference in x minus the absolute difference in y

	or 

	p is equal to the difference between twice the greatest absolute difference in x 
	or y minus the smalest.
*/

int	is_same_coordinate(t_pixel pixel_start, t_pixel pixel_end)
{
	if (pixel_start.x_pos == pixel_end.x_pos && pixel_start.y_pos == pixel_end.y_pos)
		return (1);
	return (0);
}

int differrenceTwiceGreatestLowest(t_pixel pixel_start, t_pixel pixel_end)
{
	if (pixel_end.x_pos - pixel_start.x_pos < pixel_end.y_pos - pixel_start.y_pos)
		return ((2 * absolute(pixel_end.y_pos - pixel_start.y_pos)) - absolute(pixel_end.x_pos - pixel_start.x_pos));
	return ((2 * absolute(pixel_end.x_pos - pixel_start.x_pos)) - absolute(pixel_end.y_pos - pixel_start.y_pos));
}

void	update_coordinate(t_pixel *pixel_start, t_pixel *pixel_end, int *rise_difference)
{
	if ((absolute(pixel_end->x_pos - pixel_start->x_pos)) < (absolute(pixel_end->y_pos - pixel_start->y_pos)))
	{
		if (pixel_start->y_pos < pixel_end->y_pos)
			pixel_start->y_pos++ ;
		else
			pixel_start->y_pos-- ;
	}
	else
		if (pixel_start->x_pos < pixel_end->x_pos)
			pixel_start->x_pos++ ;
		else
			pixel_start->x_pos-- ;
	if (*rise_difference < 0)
		// [ ] finish function
}

// [ ] int	update_rise()

void	draw_line(void *img, t_pixel pixel_start, t_pixel pixel_end)
{
	int rise_difference = differenceTwiceGreatestLowest(pixel_start, pixel_end);
	while (!(is_same_coordonate(pixel_start, pixel_end)));
	{
		my_mlx_pixel_put(img, pixel_start.x_pos, pixel_start.y_pos, RED);
		update_coordinate(&pixel_start, &pixel_end, rise_difference);
		update_rise_difference(&pixel_start, pixel_end, rise_difference);
	}
}