/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:27 by jcourtem          #+#    #+#             */
/*   Updated: 2022/02/09 15:53:13 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <fcntl.h>
#include <stdio.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"

int	get_y(char *c_data)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	while (c_data[i++] != '\n')
	{
		if (c_data[i] == 32)
		{
			while (c_data[i] == 32)
				i++;
			if (c_data[i] != 32 && c_data[i] != '\n')
				x++;
		}
	}
	return (x);
}

int	get_x(char *c_data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (c_data[i])
	{
		if (c_data[i] == '\n')
			y++ ;
		i++ ;
	}
	return (y);
}

t_pixel	**create_empty_map(int x, int y)
{
	t_pixel		**map;
	int			i;

	i = 0;
	map = (t_pixel **)malloc(sizeof(t_pixel) * x);
	while (i <= x)
		map[i++] = malloc(sizeof(t_pixel) * y);
	return (map);
}

void	fill_map_data(t_pixel **map, char *c_data)
{
	int	x;
	int	y;
	int	i;
	int base = 10;

	x = 0;
	y = 0;
	i = 0;
	while (c_data[i])
	{
		map[x][y].x_pos = x * base;
		map[x][y].y_pos = y * base;
		if (c_data[i] >= 33 && c_data[i] <= 126)
		{
			map[x][y].z_pos = ft_atoi(c_data + i);
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

t_pixel	**parsing_char_to_t_pixel(int fd)
{
	char	*c_data;
	char	buffer[100001];
	int		bytes;
	t_pixel	**map;

	bytes = 1;
	c_data = malloc(sizeof(char *) * 1000000000);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 100000);
		buffer[bytes] = '\0';
		if (bytes > 0)
			c_data = gnl_strcat(c_data, buffer);
	}
	map = create_empty_map(get_x(c_data), get_y(c_data));
	fill_map_data(map, c_data);
	return (map);
}
