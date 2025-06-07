/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:12:26 by gita              #+#    #+#             */
/*   Updated: 2025/06/07 16:48:21 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*look_for_line(char *result, char *findnl)
{
	size_t	i;
	char	*join;
	char	*before_nl;

	if (findnl == NULL)
		return (result);
	if (!ft_strchr(findnl, '\n'))
	{
		join = ft_strjoin(result, findnl);
		if (join == NULL)
		{
			free(result);
			return (NULL);
		}
	}
	if (ft_strchr(findnl, '\n'))
	{
		
	}
	return (join);
}

static char	*keep_reading(char *findnl, int fd)
{
	ssize_t	alr_read;
	
	alr_read = read(fd, findnl, BUFFER_SIZE);
	if (alr_read < 0)
		return (NULL);
	findnl[alr_read]  = '\0';
		
}

char	*get_next_line(int fd)
{
	static char	find_nl[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	if (find_nl)
}
