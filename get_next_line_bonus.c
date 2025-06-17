/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:37:33 by gita              #+#    #+#             */
/*   Updated: 2025/06/17 14:56:31 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*wipe_this(char *trash)
{
	free (trash);
	trash = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	find_nl[FDNUM][BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || fd > FDNUM || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	while (1)
	{
		if (find_nl[fd][0] != 0)
		{
			result = keep_joining(result, find_nl[fd]);
			if (result == NULL)
				return (NULL);
			if (ft_strchr(result, '\n'))
				break ;
		}
		if (keep_reading(find_nl[fd], fd) <= 0)
			break ;
	}
	if (result != NULL && result[0] != 0)
		return (result);
	return (wipe_this(result));
}

ssize_t	keep_reading(char *findline, int fd)
{
	ssize_t	alr_read;

	alr_read = read(fd, findline, BUFFER_SIZE);
	if (alr_read < 0)
		return (alr_read);
	findline[alr_read] = '\0';
	return (alr_read);
}

char	*keep_joining(char *res, char *findnl)
{
	char	*firstpart;
	char	*joined;

	if (findnl == NULL)
		return (res);
	if (ft_strchr(findnl, '\n'))
	{
		firstpart = line_extract_n_update_buf(findnl);
		if (!firstpart)
			return (wipe_this(res));
		joined = ft_strjoin(res, firstpart);
		if (!joined)
		{
			wipe_this(firstpart);
			return (wipe_this(res));
		}
		wipe_this(firstpart);
		wipe_this(res);
		return (joined);
	}
	joined = ft_strjoin(res, findnl);
	if (!joined)
		return (wipe_this(res));
	wipe_this(res);
	return (joined);
}

char	*line_extract_n_update_buf(char *thereisline)
{
	char	*before_nl;
	size_t	i;
	size_t	p;

	if (thereisline == NULL)
		return (NULL);
	i = 0;
	while (thereisline[i] && thereisline[i] != '\n')
		i++;
	if (thereisline[i] == '\n')
		i++;
	before_nl = ft_substr(thereisline, 0, i);
	if (!before_nl)
		return (NULL);
	p = 0;
	while (thereisline[i])
		thereisline[p++] = thereisline[i++];
	thereisline[p] = '\0';
	return (before_nl);
}
