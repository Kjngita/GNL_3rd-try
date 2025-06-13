/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:12:26 by gita              #+#    #+#             */
/*   Updated: 2025/06/13 15:47:58 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_extraction(char *whole, char *chunk)
{
	char	*before_nl;
	char	*theline;
	size_t	i;

	i = 0;
	while (chunk[i] && chunk[i] != '\n')
		i++;
	if (chunk[i] == '\n')
		i++;
	before_nl = ft_substr(chunk, 0, i);
	if (!before_nl)
		return (whole);
	theline = ft_strjoin(whole, before_nl);
	
	free (whole);
	return (theline);
}

static char	*keep_joining(char *result, char *findnl)
{
	char	*join;

	if (findnl == NULL)
		return (result);
	if (ft_strchr(findnl, '\n'))
	{
		return (line_extraction(result, findnl));
		// join = line_extraction(result, findnl);
		// if (join == NULL)
		// {
		// 	free (result);
		// 	return (NULL);
		// }
		// free (result);
		// return (join);
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

char	*get_next_line(int fd)
{
	static char	find_nl[BUFFER_SIZE + 1];
	char		*result;
	ssize_t		alr_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	result = keep_joining(result, find_nl);
	if (ft_strchr(result, '\n'))
		return (result);
	alr_read = read(fd, find_nl, BUFFER_SIZE);
	if (alr_read < 0)
	{
		free (result);
		return (NULL);
	}
	find_nl[alr_read] = '\0';
	while(alr_read > 0)
	{
		result = keep_joining(result, find_nl);
		if (ft_strchr(result, '\n'))
			return (result);
	}
}

