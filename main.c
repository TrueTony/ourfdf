#include "fdf.h"

void     colors(int key, t_fdf *data)
{
    if (key == 18)
    {
        data->color1 = 0x00FFFF;
        data->color2 = 0xADFF2F;
    }
    if (key == 19)
        data->color1 = 0x00FFFF;
    if (key == 20)
        data->color1 = 0xE0FFFF;
    if (key == 21)
        data->color1 = 0xAFEEEE;
    if (key == 22)
        data->color1 = 0x7FFFD4;
    if (key == 23)
        data->color1 = 0x40E0D0;
    if (key == 24)
        data->color1 = 0x48D1CC;
    if (key == 25)
        data->color1 = 0x00CED1;
    if (key == 26)
        data->color1 = 0x5F9EA0;
    if (key == 27)
        data->color1 = 0x4682B4;
}

int    deal_key(int key, t_fdf *data)
{
    printf("%d\n", key);
    if (key == 126 && data->shift_y > -3000)
        data->shift_y -= 10;
    if (key == 125 && data->shift_y > 3000)
        data->shift_y += 10;
    if (key == 123 && data->shift_x > -3000)
        data->shift_x -= 10;
    if (key == 124 && data->shift_x > 3000)
        data->shift_x += 10;
    if (100 - key >= 73 && 100 - key <= 92)
        colors(key, data);
    if (key == 53)
        exit(1);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}

int     main(int argc, char **argv)
{
    t_fdf   *data;

    if (argc == 2)
    {
        data = (t_fdf*)malloc(sizeof(t_fdf));
        read_file(argv[1], data);
        /*
        int i = 0;
        int j = 0;

        while (i < data->height)
        {
            j = 0;
            while( j < data->width)
            {
                printf("%3d ", data->z_matrix[i][j]);
                j++;
            }
            i++;
            printf("\n");
        }
        */
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
    data->zoom = 20;
    data->shift_x = 300;
    data->shift_y = 300;
    data->color1 = 0x87CEEB;
    data->color2 = 0xFF1493;
    //mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, #color);
    //bresenham(10, 10, 600, 300, data);
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
    }
    else
        ft_putstr("Usage: ./fdf MAP_FILE");
    return (0);
}
