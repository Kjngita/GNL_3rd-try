/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:38:15 by gita              #+#    #+#             */
/*   Updated: 2025/06/17 16:19:14 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 68
# endif

# ifndef FDNUM
#  define FDNUM 68
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
ssize_t	keep_reading(char *findline, int fd);
char	*keep_joining(char *res, char *findnl);
char	*line_extract_n_update_buf(char *thereisline);

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, unsigned char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, unsigned int start, size_t len);

#endif