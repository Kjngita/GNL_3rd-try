/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:12:26 by gita              #+#    #+#             */
/*   Updated: 2025/06/05 22:29:33 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*keep_reading(char *findnl, int fd)
{
	ssize_t	alr_read;
	
	while (!ft_strchr(findnl, '\n'))
	{
		alr_read = read(fd, findnl, BUFFER_SIZE);
		if (alr_read < 0)
			return (NULL);
		findnl[alr_read]  = '\0';
		
	}
}

char	*get_next_line(int fd)
{
	static char	find_nl[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	if (find_nl != NULL)
	{
		result = ft_strchr(find_nl, '\n');
		return (result);
	}
}
