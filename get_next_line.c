/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:43:40 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/06 19:36:19 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_new_line(char **str, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	*line = ft_strsub(str[fd], 0, len);
	if (str[fd][len] == '\0')
	{
		ft_strdel(&str[fd]);
		return (1);
	}
	tmp = ft_strdup(str[fd] + len + 1);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}

int		itsokay(const int fd, char **line)
{
	if (fd < 0 || fd > 10240 || line == NULL || read(fd, NULL, 0) == -1
		|| BUFF_SIZE <= 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[10240];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		size;

	if (itsokay(fd, line))
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	if (ft_strchr(str[fd], '\n'))
		return (ft_new_line(str, line, fd));
	while ((size = read(fd, buff, BUFF_SIZE)))
	{
		buff[size] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (size < 0)
		return (-1);
	else if (size == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_new_line(str, line, fd));
}
