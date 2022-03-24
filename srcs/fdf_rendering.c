#include "../includes/fdf.h"
#include <stdio.h>

// [ ] clean

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

void render(t_pixel **map, t_mlx mlx)
{   

}