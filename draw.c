/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:09:09 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/07 16:26:58 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	bresenham(t_point start, t_point end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	data->color = (start.z || end.z) ? data->color1 : data->color2;
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = maxn(modn(x_step), modn(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(end.x - start.x) || (int)(end.y - start.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start.x, start.y, data->color);
		start.x += x_step;
		start.y += y_step;
	}
}

t_point		pre_bresenham(float x, float y, t_fdf *data)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = data->z_matrix[(int)y][(int)x] * data->chchchaaanges;
	p.x *= data->zoom;
	p.y *= data->zoom;
	if (data->isom)
		isometric(&p.x, &p.y, p.z, data->angle);
	p.x += data->shift_x;
	p.y += data->shift_y;
	return (p);
}

void	draw(t_fdf *data)
{
	float	x;
	float	y;
	//t_point	*p;

	//p = (t_point*)malloc(sizeof(t_point));
	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if (x < data->width - 1)
				bresenham(pre_bresenham(x, y, data), pre_bresenham(x + 1, y, data), data);
			if (y < data->height - 1)
				bresenham(pre_bresenham(x, y, data), pre_bresenham(x, y + 1, data), data);
			x++;
		}
		y++;
	}
	print_menu(data);
	//free(p);
}
