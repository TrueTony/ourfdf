/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:39:15 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/07 18:49:57 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		maxn(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		minn(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		modn(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}
