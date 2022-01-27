
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>

#include "../includes/fdf.h"
#include "../includes/libft.h"


/* 
    This function is used to parse the data found in a .fdf file to a **map of t_pixel with x pos, y pos, and z pos.
    getting a int fd representing the <file>.fdf, we need to be able to turn the values in the files from a char *, to a t_pixel **map,
    it start by read() data from fd to a char *c_data varriable.
    it creates a t_pixel **map, with x = longest line in c_data, and y = # of '\n' char in c_data.
*/

//measure longest line in from 0 to '\n' or from '\n'+1 to '\n' and return value x for **map
int get_x(char *c_data)
{
    int x_save;
    int x_current;
    int i;

    i = 0;
    x_current = 0;
    x_save = 0;
    while (c_data[i])
    {
        if ((c_data[i] >= 48 && c_data[i] <= 57) || c_data[i] == 45)
        {
            x_current++;
            while ((c_data[i] >= 48 && c_data[i] <= 57) || c_data[i] == 45)
                i++;
        }
        while (c_data[i] == 32)
            i++;
        if (c_data[i] == '\n')
        {
            if (x_current > x_save)
                x_save = x_current;
            x_current = 0;
            i++ ;
        }
    }
    return (x_save);
}

//measure # of '\n' in c_data and return value y for **map.
int get_y(char *c_data)
{
    int i;
    int y;

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
t_pixel **create_empty_map(int x,int y)
{
    t_pixel **map;
    int     i;

    i = 0;
    map = (t_pixel **)malloc(sizeof(t_pixel) * y);
    while (i <= y)
        map[i++] = malloc(sizeof(t_pixel) * x + 1);
    return (map);
}

// after the creation of t_pixel map[get_x(c_data)][get_y(c_data)], we can parse char to int from c_data into the map itself.
void    fill_map_data(t_pixel **map, char *c_data)
{
    int col;
    int row;
    int x;
    int y;
    int i;

    col = get_x(c_data);
    row = get_y(c_data);
    x = 0;
    y = 0;
    i = 0;
    while (y <= row)
    {
        while (x <= col)
        {
            map[x][y].x = x;
            map[x][y].y = y;
            if ((c_data[i] >= 48 && c_data[i] <= 57) || c_data[i] == 45)
            {
                map[x][y].z = ft_atoi(c_data + i);
                x++;
                while ((c_data[i] >= 48 && c_data[i] <= 57) || c_data[i] == 45)
                    i++;
            }
            while (c_data[i] == 32)
                i++;
            if (c_data[i] == '\n')
            {
                i++;
                y++;
                x = 0;
            }
        }
        y++;
    }
}



// read() from fd to c_data everything that is found in fd.
// make t_pixel **map with c_data
// parse c_data to int in **map
void    parsing_char_to_t_pixel(fd)
{
    char    *c_data = NULL;
    char    buffer[1024];
    int     bytes;
    t_pixel **map;

    bytes = 1;
    while (bytes > 0)
    {
        bytes = read(fd, buffer, 1024);
        if (bytes > 0)
            c_data = gnl_strcat(c_data, buffer);
    }
    int y = get_y(c_data);
    int x = get_x(c_data);
    map = create_empty_map(get_x(c_data), get_y(c_data));
    fill_map_data(map, c_data);
    printf("\nc_data = \n%s\n\ny = %d\n\nx = %d\n\nmap[3][3] = %d\n\n", c_data, y, x, map[3][3].z);
}

// main for testing purposes. 
int main(int argc, char **argv)
{
    int fd;

    fd = open(argv[1], O_RDWR);
    if (argc < 2)
    {
        printf("Invalide number of args. Minimum 1 (file.fdf)");
        return (0);
    }
    parsing_char_to_t_pixel(fd);
    return (0);
}