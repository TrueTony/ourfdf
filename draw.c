/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:09:09 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/06 21:05:08 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	bresenham(float xx[2], float yy[2], t_fdf *data)
{

	float 	x = xx[0];
	float	x1 = xx[1];
	float	y = yy[0];
	float	y1 = yy[1];
	printf("%f %f %f %f\n", x, x1, y, y1);


	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x] * data->chchchaaanges;
	z1 = data->z_matrix[(int)y1][(int)x1] * data->chchchaaanges;

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	data->color = (z || z1) ? data->color1 : data->color2;
	if (data->isom)
	{
		isometric(&x, &y, z, data->angle);
		isometric(&x1, &y1, z1, data->angle);
	}
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = maxn(modn(x_step), modn(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}
/*
void	pre_bresenham(float x, float y, float x1, float y1, t_fdf *data)
{

}
*/
void	draw(t_fdf *data)
  {
	float	x[2];
	float	y[2];

	y[0] = 0;
	while(y[0] < data->height)
	{
		x[0] = 0;
		while(x[0] < data->width)
		{
			if (x[0] < data->width - 1)
			{
				x[1] = x[0] + 1;
				y[1] = y[0];
				bresenham(x, y, data);
			}
			if (y[0] < data->height - 1)
			{
				x[1] = x[0];
				y[1] = y[0] + 1;
				bresenham(x, y, data);
			}
			x[0]++;
		}
		y[0]++;
	}
	print_menu(data);
  }