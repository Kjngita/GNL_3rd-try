/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:41:03 by gita              #+#    #+#             */
/*   Updated: 2025/06/16 21:34:39 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, unsigned char c)
{
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] || c == '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	p;
	char	*unite;

	if (s2 == NULL || *s2 == 0)
		return (s1);
	unite = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!unite)
		return (NULL);
	i = 0;
	while (i++ < ft_strlen(s1))
		unite[i] = s1[i];
	p = 0;
	while (s2[p])
		unite[i++] = s2[p++];
	unite[i] = '\0';
	return (unite);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*babystr;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (len > (ft_strlen(str) - start))
		len = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		len = 0;
	i = 0;
	babystr = malloc(len + 1);
	if (!babystr)
		return (NULL);
	while (len > 0)
	{
		babystr[i++] = str[start++];
		len--;
	}
	babystr[i] = '\0';
	return (babystr);
}
