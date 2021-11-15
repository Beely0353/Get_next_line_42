/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:53:05 by baroun            #+#    #+#             */
/*   Updated: 2021/11/15 16:30:46 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char static	*buf;
	int			ret;

	if (!fd)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	return (buf);
}


int main()
{
	int	fd;

	fd = open("texte.txt", O_RDONLY);
	printf("la :%s\n", get_next_line(fd));
}
