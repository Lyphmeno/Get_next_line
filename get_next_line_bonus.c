/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:35:00 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/14 14:25:24 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i--;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*buf_reset(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

static char	*buf_read(int fd, char *buffer)
{
	char	*tmpBuf;
	int		bytes;

	tmpBuf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmpBuf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, tmpBuf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmpBuf);
			return (NULL);
		}
		tmpBuf[bytes] = '\0';
		buffer = ft_strjoin(buffer, tmpBuf);
	}
	free(tmpBuf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = buf_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = buf_reset(buffer[fd]);
	return (line);
}
