/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:29 by baroun            #+#    #+#             */
/*   Updated: 2021/11/22 17:50:30 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd);

#endif
