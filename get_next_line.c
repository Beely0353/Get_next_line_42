/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:53:05 by baroun            #+#    #+#             */
/*   Updated: 2021/11/22 17:29:52 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_only_line(char *buf)
{
	char	*only_line;
	int		sbuf;
	int		sal;

	if (buf == NULL)
		return (NULL);
	sbuf = ft_strlen(buf);
	sal = ft_strlen(ft_strchr(buf, '\n')) - 1;
	only_line = (char *) malloc(sbuf - sal + 1);
	ft_strlcpy(only_line, buf, sbuf - sal + 1);
	return (only_line);
}

char	*buf_line(char	*buf, char	*only_line)
{
	char	*rbuf;
	int		sline;
	int		stot;

	if (buf == NULL || only_line == NULL)
		return (NULL);
	stot = ft_strlen(buf);
	sline = ft_strlen(only_line);
	if (sline <= 0)
	{
		free(buf);
		return (NULL);
	}
	rbuf = malloc(stot - sline + 1);
	ft_strlcpy(rbuf, buf + sline, stot - sline + 1);
	free(buf);
	return (rbuf);
}

static	char	*gnl_cat(char	*buf, char	*mbufsize)
{
	char	*rbuf;
	int		sbuf;
	int		smbuf;

	if (buf == NULL || mbufsize == NULL)
		return (NULL);
	sbuf = ft_strlen(buf) + 1;
	smbuf = ft_strlen(mbufsize);
	rbuf = malloc(sbuf + smbuf);
	ft_strlcpy(rbuf, buf, sbuf);
	ft_strcat(rbuf, mbufsize);
	free(buf);
	return (rbuf);
}

static char	*get_line(int fd, char	*buf)
{
	char	*mbufsize;
	int		ret;

	mbufsize = (char *) malloc(BUFFER_SIZE + 1);
	if (!mbufsize)
	{
		free(mbufsize);
		free(buf);
		return (NULL);
	}
	ret = 42;
	while (ret && !ft_strchr(buf, '\n'))
	{
		ret = read(fd, mbufsize, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			free(mbufsize);
			return (NULL);
		}
		mbufsize[ret] = 0;
		buf = gnl_cat(buf, mbufsize);
	}
	free(mbufsize);
	return (buf);
}

char	*get_next_line(int fd)
{
	char static	*buf;
	char		*only_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
		buf = ft_strdup("");
	buf = get_line(fd, buf);
	if (buf == NULL)
		return (NULL);
	only_line = get_only_line(buf);
	buf = buf_line(buf, only_line);
	if (only_line[0] == '\0')
	{
		free(buf);
		free(only_line);
		return (NULL);
	}
	return (only_line);
}
