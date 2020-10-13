/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:33:20 by hlevi             #+#    #+#             */
/*   Updated: 2020/02/18 16:11:41 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*eol_pos(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i])
		return (&buff[i]);
	return (0);
}

int		line_realloc(char *str, char **line)
{
	char	*buff;
	int		len;

	if (!*line)
	{
		if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (-1);
		ft_strcpyn(*line, str);
		return (0);
	}
	len = ft_strlen(str) + ft_strlen(*line);
	if (!(buff = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	ft_strcpyn(buff, *line);
	ft_strcatn(buff, str);
	free(*line);
	*line = buff;
	return (0);
}

int		checkbuff(char *buff, char **line)
{
	char	*eol;

	if (ft_strlen(buff))
	{
		eol = eol_pos(buff);
		if (eol)
		{
			*eol = '\0';
			if (line_realloc(buff, line))
				return (-1);
			ft_strcpyn(buff, (eol + 1));
			return (1);
		}
		if (line_realloc(buff, line))
			return (-1);
	}
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	return (0);
}

void	free_for_norm(char **buff, int fd)
{
	free(buff[fd]);
	buff[fd] = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char	*buff[OPEN_MAX];
	int			check;
	int			count;

	if (fd < 0 || fd >= OPEN_MAX || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	*line = NULL;
	if (!buff[fd])
		if (!(buff[fd] = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
	if ((check = checkbuff(buff[fd], line)))
		return ((check = 1) ? 1 : -1);
	while ((count = read(fd, buff[fd], BUFFER_SIZE)))
	{
		if (count == -1)
			return (-1);
		buff[fd][count] = '\0';
		if ((check = checkbuff(buff[fd], line)))
			return ((check = 1) ? 1 : -1);
	}
	if (!*line)
		if (!(*line = (char *)ft_calloc(1, sizeof(char))))
			return (-1);
	free_for_norm(buff, fd);
	return (0);
}
