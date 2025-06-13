/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:12:26 by gita              #+#    #+#             */
/*   Updated: 2025/06/13 16:42:41 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_extract_n_update_buf(char *str)
{
	char	*before_nl;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	before_nl = ft_substr(str, 0, i);
	if (!before_nl)
		return (NULL);
	if (ft_strchr(before_nl, '\n'))
	{
		while (str[i])
			str[k++] = str[i++];
		str[k] = '\0';
	}
	return (before_nl);
}

static char	*keep_joining(char *result, char *findnl)
{
	char	*first_part;
	char	*join;

	if (findnl == NULL)
		return (result);
	if (ft_strchr(findnl, '\n'))
	{
		first_part = line_extract_n_update_buf(findnl);
		if (!first_part)
		{
			free (result);
			return (NULL);
		}
		join = ft_strjoin(result, first_part);
		free (first_part);
		return (join);
	}
	join = ft_strjoin(result, findnl);
	if (join == NULL)
	{
		free(result);
		return (NULL);
	}
	free(result);
	return (join);
}
static ssize_t	keep_reading(char *findingnl, int fd)
{
	ssize_t	alr_read;

	alr_read = read(fd, findingnl, BUFFER_SIZE);
	if (alr_read < 0)
		return (alr_read);
	findingnl[alr_read] = '\0';
	return (alr_read);
}

char	*get_next_line(int fd)
{
	static char	find_nl[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	while (1)
	{
		if (*find_nl)
		{
			result = keep_joining(result, find_nl);
			if (!result)
				return(NULL);
		}
		if (keep_reading <= 0)
			break ;
	}
}

