#include "fdf.h"

int    deal_key(int key, void *data)
{
    printf("%d", key);
    return (0);
}

int     main(int argc, char **argv)
{
    t_fdf   *data;

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
   //mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, #color);
   //bresenham(10, 10, 600, 300, data);
   draw(data);
   mlx_key_hook(data->win_ptr, deal_key, NULL);
   mlx_loop(data->mlx_ptr);

    return (0);
}