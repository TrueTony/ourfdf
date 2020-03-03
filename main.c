#include "fdf.h"

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
    data->chchchaaanges = 1;
    //mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, #color);
    //bresenham(10, 10, 600, 300, data);
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
    }
    else
        ft_putstr("Usage: ./fdf MAP_FILE\n");
    return (0);
}
