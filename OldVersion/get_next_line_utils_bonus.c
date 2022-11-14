/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:34:26 by hlevi             #+#    #+#             */
/*   Updated: 2020/02/18 11:02:51 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpyn(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_strcatn(char *dst, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(dst);
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
}

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	chr;
	int				i;
	char			*str;

	str = s;
	i = 0;
	chr = (unsigned char)c;
	while (i < n)
	{
		str[i] = chr;
		i++;
	}
	return (s);
}

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	if (!(ptr = malloc(size * count)))
		return (NULL);
	return (ft_memset(ptr, 0, count * size));
}
