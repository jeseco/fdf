/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:27 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/20 15:03:39 jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/libft.h"

void	set_xy_coordonate(t_map *map, int x, int y)
{
	if (!y)
	{	
		if (x > y)
		{
			map->vertex[x][y].x_pos = map->vertex[0][0].x_pos - \
			((3 * map->base) * x);
			map->vertex[x][y].y_pos = map->vertex[0][0].y_pos + \
			((2 * map->base) * x);
		}
	}
	else
	{
		map->vertex[x][y].x_pos = map->vertex[x][y - 1].x_pos + (3 * map->base);
		map->vertex[x][y].y_pos = map->vertex[x][y - 1].y_pos + (2 * map->base);
	}
}

int	get_z_coordonate(char *c_data, int i)
{
	int	z_pos;

	z_pos = 0;
	if (c_data[i] >= 33 && c_data[i] <= 126)
		z_pos = ft_atoi(c_data + i);
	return (z_pos);
}

void	fill_map_data(t_map *map, char *c_data)
{
	int		x;
	int		y;
	long	i;

	x = 0;
	y = 0;
	i = 0;
	while (c_data[i])
	{
		set_xy_coordonate(map, x, y);
		map->vertex[x][y].z_pos = get_z_coordonate(c_data, i);
		y++;
		while (c_data[i] != 32 && c_data[i] != '\n' && c_data[i] != '\0')
			i++;
		while (c_data[i] == 32)
			i++;
		if (c_data[i] == '\n')
		{
			i++ ;
			y = 0;
			x++ ;
		}
		if (c_data[i] == '\0')
			return ;
	}
}

t_map	parsing(int fd)
{
	t_map	map;
	char	*buffer;
	char	*c_data;
	size_t	line_len;

	buffer = get_next_line(fd);
	c_data = NULL;
	line_len = ft_strlen(buffer);
	while (buffer != NULL)
	{
		c_data = ft_strjoin(c_data, buffer);
		buffer = get_next_line(fd);
	}
	map = init_map(get_x(c_data), get_y(c_data));
	fill_map_data(&map, c_data);
	free (buffer);
	free (c_data);
	return (map);
}
