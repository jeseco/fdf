/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:13:31 by jcourtem          #+#    #+#             */
/*   Updated: 2022/03/30 12:41:01 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include "libft.h"

# define RED 			0x00ff0000
# define GREY 			0x01808080
# define WIDTH 			1920
# define HEIGHT 		1080
# define ESC_KEY		53

typedef struct s_vertex {
	int	x_pos;
	int	y_pos;
	int	z_pos;
	int color;
}	t_vertex;

typedef struct s_map {
	int 		x_size;
	int 		y_size;
	int			base;
	t_vertex	**vertex;
}	t_map;

typedef struct s_mlx{
	void *server;
	void *window;
}		t_mlx;

typedef struct s_data {
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

// 			from fdf_utils: 
int		creat_trgb(int t, int r, int g, int b);

int		get_t(int trgb);

int		get_r(int trgb);

int 	get_g(int trgb);

int 	get_b(int trgb);

int 	absolute(int a);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		get_x(char *c_data);

int		get_y(char *c_data);

t_map	parsing(char *str);

void	draw_line(t_mlx *mlx, t_vertex start, t_vertex end);

void 	render(t_map map, t_mlx *mlx);

int 	handle_key_input(int key, t_mlx *mlx);

#endif
