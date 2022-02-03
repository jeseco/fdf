/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:27 by jcourtem          #+#    #+#             */
/*   Updated: 2022/02/03 16:47:44 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <fcntl.h>
#include <stdio.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"

/* 
    This function is used to parse the data found in a .fdf file to a **map of 
        t_pixel with x pos, y pos, and z pos.
    getting a int fd representing the <file>.fdf, we need to be able to turn 
        the values in the files from a char *, to a t_pixel **map,
    it start by read() data from fd to a char *c_data varriable.
    it creates a t_pixel **map, with x = longest line in c_data, and y = # of
        '\n' char in c_data.
*/

//measure longest line in from 0 to '\n' or from '\n'+1 to '\n' and return 
// value x for **map
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

//measure # of '\n' in c_data and return value y for **map.
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

// generates an empty map of type t_pixel ** with malloc.
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

// after the creation of t_pixel map[get_x(c_data)][get_y(c_data)], we can 
// parse char to int from c_data into the map itself.
void	fill_map_data(t_pixel **map, char *c_data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (c_data[i])
	{
		map[x][y].x_pos = x;
		map[x][y].y_pos = y;
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

// read() from fd to c_data everything that is found in fd.
// make t_pixel **map with c_data
// parse c_data to int in **map
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
