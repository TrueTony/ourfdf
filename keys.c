/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:47:55 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/07 20:31:21 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	isom(t_fdf *data)
{
	if (data->isom == 0)
		data->isom = 1;
	else
		data->isom = 0;
}

void	zooom(t_fdf *data, int key)
{
	int	step;

	step = data->zoom / 2;
	if (step == 0)
		step = 1;
	if (key == 6 && (data->zoom - step > 0))
		data->zoom -= step;
	if (key == 7 && (data->zoom + step < 500))
		data->zoom += step;
}

void	change_z(t_fdf *data, int key)
{
	int	step;

	step = 1;
	if (key == 29)
		data->chchchaaanges *= -1;
	if (key == 24 && data->chchchaaanges < 50)
		data->chchchaaanges += step;
	if (key == 27 && data && data->chchchaaanges > -50)
		data->chchchaaanges -= step;
}

void	shift(int key, t_fdf *data)
{
	if (key == 126 && data->shift_y > -5000)
		data->shift_y -= 10;
	if (key == 125 && data->shift_y < 5000)
		data->shift_y += 10;
	if (key == 123 && data->shift_x > -5000)
		data->shift_x -= 10;
	if (key == 124 && data->shift_x < 5000)
		data->shift_x += 10;
}

int		deal_key(int key, t_fdf *data)
{
	if (key >= 123 && key <= 126)
		shift(key, data);
	if (key == 18 || key == 19 || (key >= 20 && key <= 26) \
		|| key == 28 || key == 29)
		change_colors(key, data);
	if (key == 6 || key == 7)
		zooom(data, key);
	if (key == 29 || key == 27 || key == 24)
		change_z(data, key);
	if (key == 49)
		isom(data);
	if (key == 2)
		disco(data, key);
	if (key == 4)
		hide(data);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(1);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
