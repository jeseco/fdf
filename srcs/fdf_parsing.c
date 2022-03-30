/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:27 by jcourtem          #+#    #+#             */
/*   Updated: 2022/03/30 13:51:52 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [ ] clean 

#include <limits.h>
#include <fcntl.h>
#include <stdio.h>

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
	map.base = 50;
	map.vertex = malloc(sizeof(t_vertex *) * x);
	while (i < x)
		map.vertex[i++] = malloc(sizeof(t_vertex *) * y);
	map.vertex[0][0].x_pos = WIDTH / 2;
	map.vertex[0][0].y_pos = 10;
	return (map);
}

void	fill_map_data(t_map *map, char *c_data)
{
	int	x;
	int	y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (c_data[i])
	{
		if (!y)
		{	
			if (x > y)
			{
				map->vertex[x][y].x_pos = map->vertex[0][0].x_pos - ((3 * map->base) * x);
				map->vertex[x][y].y_pos = map->vertex[0][0].y_pos + ((2 * map->base) * x);
			}
		}
		else
		{
			map->vertex[x][y].x_pos = map->vertex[x][y - 1].x_pos + (3 * map->base);
			map->vertex[x][y].y_pos = map->vertex[x][y - 1].y_pos + (2 * map->base); // [ ] sigsev
		}
		if (c_data[i] >= 33 && c_data[i] <= 126)
		{
			map->vertex[x][y].z_pos = ft_atoi(c_data + i);
			y++;
			while (c_data[i] != 32 && c_data[i] != '\n' && c_data[i] != '\0')
				i++;
		}
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

t_map	parsing(char *file_name)
{
	t_map	map;
	char	*buffer;
	char	*c_data;
	int		bytes;

	int fd;
	bytes = 1;
	fd = open(file_name, O_RDONLY);
	buffer = get_next_line(fd);
	c_data = NULL;
	// ft_bzero(c_data, ft_strlen(c_data));
	while (buffer != NULL)
	{
		c_data = ft_strjoin(c_data, buffer);
		buffer = get_next_line(fd);
	}
	map = init_map(get_x(c_data), get_y(c_data));
	fill_map_data(&map, c_data);
	return (map);
}
