/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:10:15 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/07 21:17:40 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		height++;
		free(line);
	}
	close(fd);
	if (height == 0)
	{
		ft_putstr("Error: incorrect file\n");
		exit(1);
	}
	return (height);
}

int		get_width(char *file_name, t_fdf *d)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = counter(line, ' ');
	free(line);
	height = d->height - 1;
	while (height--)
	{
		get_next_line(fd, &line);
		if (width != counter(line, ' '))
		{
			free(line);
			close(fd);
			return (0);
		}
		width = counter(line, ' ');
		free(line);
	}
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int		width_and_height(char *file_name, t_fdf *d)
{
	d->height = get_height(file_name);
	d->width = get_width(file_name, d);
	if (!d->width)
	{
		ft_putstr("Error: incorrect file\n");
		exit(1);
	}
	return (1);
}

void	read_file(char *file, t_fdf *d)
{
	int		fd;
	int		i;
	char	*line;

	if (width_and_height(file, d))
	{
		if (!(d->z_mat = (int**)malloc(sizeof(int*) * (d->height + 1))))
			return ;
		i = 0;
		while (i <= d->height)
			if (!(d->z_mat[i++] = (int*)malloc(sizeof(int) * (d->width + 1))))
				return ;
		fd = open(file, O_RDONLY, 0);
		i = 0;
		while (get_next_line(fd, &line))
		{
			fill_matrix(d->z_mat[i++], line);
			free(line);
		}
		close(fd);
		return ;
	}
	ft_putstr("Error: incorrect file\n");
	exit(0);
}
