#include "../includes/fdf.h"
#include <stdio.h>

// [ ] clean

char *make_str(int fd)
{
    char	*c_data;
	char	buffer[100001];
	int		bytes;

    bytes = 1;
	c_data = malloc(sizeof(char *) * 1000000000);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 100000);
		buffer[bytes] = '\0';
		if (bytes > 0)
			c_data = gnl_strcat(c_data, buffer);
	}
    return (c_data);
}

void iso(t_pixel **map, char *c_data)
{
    int x;
    int y;

    x = 0;
    while (x <= get_x(c_data))
    {
        y = 0;
        while(y <= get_y(c_data))
        {
            if (y == 0)
            {
                map[x][y].x_pos = map[x - 1][y].x_pos - 30;
                map[x][y].y_pos = map[x - 1][y].y_pos + 20;
            }
            else
            {
                map[x][y].x_pos = map[x][y - 1].x_pos + 20;
                map[x][y].y_pos = map[x][y - 1].y_pos + 20;
            }
            y++;
        }
        x++;
    }
}

void render(char *str, t_mlx mlx)
{   
    int     x = 0;
    int     y = 0;
    int     fd;
    char    *c_data;
    t_pixel **map;
    t_data  img;

    fd = open(str, O_RDONLY);
    c_data = make_str(fd);

    int y_max = get_y(c_data);
    int x_max = get_x(c_data);

    img.image = mlx_new_image(mlx.server, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(&img.image, &img.bits_per_pixel, &img.line_length, &img.endian);
    map = parsing_char_to_pixel(c_data);
    // iso(map, c_data);
    while (x <= get_x(c_data))
    {
        while (y < get_y(c_data))
        {
            draw_line(&img, map[x][y], map[x][y + 1]);
            y++;
            if (x > 0)
                draw_line(&img, map[x][y], map[x - 1][y]);
            if (y == get_y(c_data))
            {
                y = 0;
                x++;
                break ;
            }
        }
    }
    printf("get_y = %d \n get_x = %d\n", y_max, x_max);
    free (c_data);
}