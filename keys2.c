/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:47:55 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/07 20:31:23 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	disco(t_fdf *data, int key)
{
	float	step;

	step = 0.1;
	data->isom = 1;
	if (data->angle < -5.2)
		data->angle = 1;
	if (data->angle > 7.2)
		data->angle = 1;
	if (key == 2)
		data->angle -= step;
	if ((int)(data->angle * 10) % 2 == 0)
		data->color1 = 0x98FB98;
	else
		data->color1 = 0xF08080;
	if ((int)(data->angle * 10) % 3 == 0)
		data->color2 = 0xF0E68C;
	else
		data->color2 = 0x008B8B;
}

void	hide(t_fdf *data)
{
	data->color1 = 0x000000;
	data->color2 = 0x000000;
}
