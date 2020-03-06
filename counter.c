/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:34:30 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/06 19:34:33 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		counter(char *str, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			res++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		while (str[i] == c)
			i++;
	}
	return (res);
}
