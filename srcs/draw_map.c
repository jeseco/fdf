#include <../includes/fdf.h>

void draw_map(void *img, t_pixel **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map[x])
    {
        while (*map[y])
        {
            if (map[x][y + 1] != '\0')
                draw_line(img, map[x][y], map[x][y + 1], GREY);
            y++;
        }
        x++;
    }
}