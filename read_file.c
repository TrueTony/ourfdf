/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:05:18 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/07 16:27:09 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int     get_height(char *file_name)
{
    int     fd;
    char    *line;
    int     height;

    height = 0;
    if ((fd = open(file_name, O_RDONLY)) > 0)
    {
        while (get_next_line(fd, &line))
        {
            height++;
            free(line);
        }
        close(fd);
        return (height);
    }
    close(fd);
    ft_putstr("File does not exists\n");
    exit(1);
}

int     get_width(char *file_name)
{
    int     fd;
    char    *line;
    int     width;

    if ((fd = open(file_name, O_RDONLY)) > 0)
    {
        get_next_line(fd, &line);
        width = counter(line, ' ');
        free(line);
        close(fd);
        return (width);
    }
    close(fd);
    ft_putstr("File does not exists\n");
    exit(1);
}

int    fill_matrix(int *z_line, char *line, t_fdf *data)
{
    int     i;
    char    **nums;

    i = 0;
    nums = ft_strsplit(line, ' ');
    while (nums[i] != NULL)
        i++;
    if (i != data->width)
    {
        ft_putstr("Error: incorrect file\n");
        exit(1);
    }
    i = 0;
    while (nums[i])
    {
        printf("%d ", ft_atoi(nums[i]));
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
    return (i);
}

void    read_file(char *file_name, t_fdf *data)
{
    int     fd;
    int     i;
    char    *line;

    data->width = get_width(file_name);
    data->height = get_height(file_name);
    if (!(data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1))))
        return ;
    i = 0;
    while (i <= data->height)
    {
        if (!(data->z_matrix[i++] = (int*)malloc(sizeof(int) * \
            (data->width + 1))))
            return ;
    }
    fd = open(file_name, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->z_matrix[i++], line, data);
        free(line);
    }
    data->z_matrix[i] = NULL;
    close(fd);
}
