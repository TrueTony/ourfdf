/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:09:09 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/02 19:31:47 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

//#define MAX(a, b) (a > b ? a : b)
//#define MOD(a) (a < 0) ? -a : a

int		maxn(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		modn(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	printf("z:%d %d\n", z, z1);
	data->color1 = (z || z1) ? data->color1 : data->color2;
	//data->color1;
	//data->color;

	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

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
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color1);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
  {
	  int	x;
	  int	y;

	  y = 0;
	  while(y < data->height)
	  {
		  x = 0;
		  while(x < data->width)
		  {
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		  }
		  y++;
	  }
  }