/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:18:34 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/07 20:43:57 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		close_by_x(void *param)
{
	(void)param;
	exit(1);
}

void	init_fdf(t_fdf *data, int widthofmap, int heightofmap)
{
	data->zoom = minn(((widthofmap / 2) / (data->width / 2)) / 2, \
			((heightofmap / 2) / (data->width / 2)) / 2);
	data->shift_x = (widthofmap / 2) - ((data->width * data->zoom) / 2);
	data->shift_y = (heightofmap / 2) - ((data->height * data->zoom) / 2);
	data->color1 = 0xFFFFFF;
	data->color2 = 0xFFFFFF;
	data->chchchaaanges = 1;
	data->isom = 0;
	data->angle = 0.8;
}

void	free_matrix(t_fdf *data)
{
	int i;

	i = 0;
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
}

int		main(int argc, char **argv)
{
	t_fdf	*data;
	int		widthofmap;
	int		heightofmap;

	widthofmap = 1400;
	heightofmap = 1200;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf MAP_FILE\n");
		return (0);
	}
	data = (t_fdf*)malloc(sizeof(t_fdf));
	data->z_matrix = NULL;
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, widthofmap, \
		heightofmap, "FDF");
	init_fdf(data, widthofmap, heightofmap);
	draw(data);
	mlx_hook(data->win_ptr, 17, 0, close_by_x, data);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free_matrix(data);
	free(data);
	return (0);
}
