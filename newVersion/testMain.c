/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:53 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/14 13:58:10 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	char	*line;
	int		newFd;

	if (ac == 2)
	{
		newFd = open(av[1], O_RDONLY);
		line = get_next_line(newFd);
		printf("%s\n", line);
		while (line != NULL)
		{
			printf("%s\n", line);
			free(line);
			line = get_next_line(newFd);
		}
		close(newFd);
	}
	return (0);
}
