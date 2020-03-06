#include "fdf.h"

int		close_by_x(void *param)
{
	(void)param;
	exit(0);
}

void    init_fdf(t_fdf *data, int widthofmap, int heightofmap)
{
    data->zoom = minn(((widthofmap/2)/(data->width/2))/2, \
                    ((heightofmap/2)/(data->width/2))/2);
    data->shift_x = (widthofmap / 2) - ((data->width * data->zoom) / 2);
    data->shift_y = (heightofmap / 2) - ((data->height * data->zoom) / 2);
    data->color1 = 0xFFFFFF;
    data->color2 = 0xFFFFFF;
    data->chchchaaanges = 1;
    data->isom = 0;
    data->angle = 0.8;
}

int     main(int argc, char **argv)
{
    t_fdf   *data;
    int     widthofmap;
    int     heightofmap;

    widthofmap = 1400;
    heightofmap = 1200;
    if (argc == 2)
    {
        data = (t_fdf*)malloc(sizeof(t_fdf));
        read_file(argv[1], data);
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, widthofmap, \
                        heightofmap, "FDF");
        init_fdf(data, widthofmap, heightofmap);
        draw(data);
        mlx_hook(data->win_ptr, 17, 0, close_by_x, data);
        mlx_key_hook(data->win_ptr, deal_key, data);
        mlx_loop(data->mlx_ptr);
    }
    else
        ft_putstr("Usage: ./fdf MAP_FILE\n");
    return (0);
}
