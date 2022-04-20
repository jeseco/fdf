/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:13 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/20 15:01:55 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/libft.h"

int	get_y(char *c_data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (c_data[i] != '\n')
	{
		if (c_data[i] != 32 && c_data[i] != '\n')
		{
			y++;
			while (c_data[i] != 32 && c_data[i] != '\n')
				i++;
		}
		if (c_data[i] == 32)
		{
			while (c_data[i] == 32)
				i++;
		}
	}
	return (y);
}

int	get_x(char *c_data)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (c_data[i])
	{
		if (c_data[i] == '\n')
			x++ ;
		i++;
	}
	return (x);
}

t_map	init_map(int x, int y)
{
	t_map	map;
	int		i;

	i = 0;
	map.x_size = x;
	map.y_size = y;
	map.base = (1455 / map.y_size) / 3;
	if (map.base < 1)
		map.base = 1;
	map.vertex = (t_vertex **)malloc(sizeof(t_vertex *) * x);
	ft_bzero(map.vertex, map.x_size);
	while (i < map.x_size)
	{
		map.vertex[i] = (t_vertex *)malloc(sizeof(t_vertex) * y);
		i++;
	}
	map.vertex[0][0].x_pos = 2560 / 2;
	map.vertex[0][0].y_pos = 20;
	map.error = 0;
	return (map);
}
