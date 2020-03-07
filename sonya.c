/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sonya.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:49:44 by brandres          #+#    #+#             */
/*   Updated: 2020/03/07 20:35:13 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	print_menu(t_fdf *data)
{
	int		y;

	y = 0;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xF4A460,\
			"How to Use");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Move: Arrows");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"View: Space");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Zoom: Z/X");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Colors: 1/2/3");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Hide: H");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Flatten: -/+");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Reverse flatten: 0");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Disco: Find it by yourself");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF,\
			"Exit: ESC");
}
