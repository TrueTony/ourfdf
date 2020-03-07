/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sonya.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:49:44 by brandres          #+#    #+#             */
/*   Updated: 2020/03/07 16:27:11 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	print_menu(t_fdf *data)
{
	int		y;

	y = 0;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 65, y += 20, 0xFFFFFF, "How to Use");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 35, 0xFFFFFF, "Zoom: z/x");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Move: Arrows");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Flatten: </>");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Rotate: Press & Move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Rotate:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "X-Axis - 2/8");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "Y-Axis - 4/6");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Projection");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "ISO: I Key");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "Parallel: P Key");

}

/*void	rotation_x(float *y, int *z, float angle)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(angle) + *z * sin(angle);
	*z = -previous_y * sin(angle) + *z * cos(angle);
}

void	rotation_x(float *x, int *z, float angle)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(angle) + *z * sin(angle);
	*z = -previous_x * sin(angle) + *z * cos(angle);
}

void	rotation_x(float *x, float *y, int z, float angle)
{

}*/