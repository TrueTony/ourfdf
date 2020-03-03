/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:42:53 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/02 19:29:26 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# include <stdio.h>
# include <string.h>

//# define BUFF_SIZE  50

typedef struct  s_fdf
{
    int     width;
    int     height;
    int     zoom;
    int     color1;
    int     color2;
    int     shift_x;
    int     shift_y;
    int     **z_matrix;
    void    *mlx_ptr;
    void    *win_ptr;
}               t_fdf;

void    read_file(char *file_name, t_fdf *data);
int	    get_next_line(const int fd, char **line);
int		counter(char *str, char c);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

#endif