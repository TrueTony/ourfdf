/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:10:15 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/07 20:02:25 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <errno.h>

int     get_height(char *file_name)
{
    int     fd;
    char    *line;
    int     height;

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

int     get_width(char *file_name, t_fdf *data)
{
	int			fd;
	char		*line;
	int		width;
    int		height;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = counter(line, ' ');
	free(line);
    height = data->height - 1;
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

void    fill_matrix(int *z_line, char *line)
{
    int     i;
    char    **nums;

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

int    width_and_height(char *file_name, t_fdf *data)
{
    data->height = get_height(file_name);
    data->width = get_width(file_name, data);
    if (!data->width)
	{
		ft_putstr("Error: incorrect file\n");
		exit(1);
	}
    return (1);
}

void			read_file(char *file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	if (width_and_height(file, data))
	{
		if (!(data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1))))
            return ;
		i = 0;
		while (i <= data->height)
			if (!(data->z_matrix[i++] = (int*)malloc(sizeof(int) * \
                (data->width + 1))))
                return ;
		fd = open(file, O_RDONLY, 0);
		i = 0;
		while (get_next_line(fd, &line))
		{
			fill_matrix(data->z_matrix[i++], line);
			free(line);
		}
		close(fd);
	}
	else
	{
		ft_putstr("Error: incorrect file\n");
		exit(0);
	}
}
