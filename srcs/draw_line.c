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
	if (pixel_start.x == pixel_end.x && pixel_start.y == pixel_end.y)
		return (1);
	return (0);
}

int differrenceTwiceGreatestLowest(t_pixel pixel_start, t_pixel pixel_end)
{
	if (pixel_end.x - pixel_start.x < pixel_end.y - pixel_start.y)
		return ((2 * absolute(pixel_end.y - pixel_start.y)) - absolute(pixel_end.x - pixel_start.x));
	return ((2 * absolute(pixel_end.x - pixel_start.x)) - absolute(pixel_end.y - pixel_start.y));
}

void	update_coordinate(t_pixel *pixel_start, t_pixel *pixel_end, int *rise_difference)
{
	if ((absolute(pixel_end->x - pixel_start->x)) < (absolute(pixel_end->y - pixel_start->y)))
	{
		if (pixel_start->y < pixel_end->y)
			pixel_start->y++ ;
		else
			pixel_start->y-- ;
	}
	else
		if (pixel_start->x < pixel_end->x)
			pixel_start->x++ ;
		else
			pixel_start->x-- ;
	if (*rise_difference < 0)

}

// [ ] int	update_rise()

void	draw_line(void *img, t_pixel pixel_start, t_pixel pixel_end)
{
	int rise_difference = differenceTwiceGreatestLowest(pixel_start, pixel_end);
	while (!(is_same_coordonate(pixel_start, pixel_end)));
	{
		my_mlx_pixel_put(img, pixel_start.x, pixel_start.y, RED);
		update_coordinate(&pixel_start, &pixel_end, rise_difference);
		update_rise_difference(&pixel_start, pixel_end, rise_difference);
	}
}