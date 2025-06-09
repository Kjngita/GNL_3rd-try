/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:12:26 by gita              #+#    #+#             */
/*   Updated: 2025/06/09 21:12:51 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	keep_reading(char *findnl, int fd)
{
	ssize_t	alr_read;

	alr_read = read(fd, findnl, BUFFER_SIZE);
	if (alr_read < 0)
		return (-1);
	findnl[alr_read] = '\0';
	return (alr_read);
}

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
		i = 0;
		while (findnl[i] != '\0' && findnl[i] != '\n')
			i++;
		before_nl = ft_substr(findnl, 0, i + 1);
		join = ft_strjoin(result, before_nl);
		findnl = ft_strchr(findnl, '\n');
	}
	return (join);
}

char	*get_next_line(int fd)
{
	static char	find_nl[BUFFER_SIZE + 1];
	char		*result;
	ssize_t		anything;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	result = look_for_line(result, find_nl);
	if (ft_strchr(result, '\n'))
		return (result);
	while(!ft_strchr(result, '\n'))
	{
		anything = keep_reading(find_nl, fd);
		if (anything < 0)
		{
			free (result);
			return (NULL);
		}
		result = look_for_line(result, find_nl);
		if (ft_strchr(result, '\n'))
			return (result);
	}
}
