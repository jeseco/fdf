
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>

#include "includes/fdf.h"
#include "includes/libft.h"


/* 
    This function is used to pars the data found in a .fdf file to a **map of t_pixel with x pos, y pos, and z pos.
    getting a int fd representing the <file>.fdf, we need to be able to turn the values in the files from a char *, to a t_pixel **map,
    it start by read() data from fd to a char *c_data varriable.
    it creates a t_pixel **map, with x = longest line in c_data, and y = # of '\n' char in c_data.

*/

//measure longest line in from 0 to '\n' or from '\n'+1 to '\n' and return value a x in **map
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
        i++;
        x_current++;
        if (x_current > x_save)
            x_save = x_current;
    }
    return (x_save);
}

//measure # of '\n' in c_data and return value for y in **map.
int get_y(char *c_data)
{
    int i;
    int y;

    i = 0;
    y = 0;
    while (*c_data)
    {
        if (c_data[i] == '\n')
            y++ ;
        i++ ;
    }
    return (y);
}

// read() from fd to c_data everything that is found in fd.
// make t_pixel **map with c_data
void    parsing_char_to_t_pixel(fd)
{
    char    *c_data = NULL;
    char    buffer[1001];
    int     bytes;

    bytes = 1;
    while (bytes > 0)
    {
        bytes = read(fd, buffer, 1000);
        if (bytes > 0)
            c_data = gnl_strcat(c_data, buffer);
    }
    printf("c_data = \n%s\n", c_data);
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
}