/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:09:33 by ericlazo          #+#    #+#             */
/*   Updated: 2022/01/05 20:58:07 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"


char	*get_line(char **line, char **b_read)
{
	size_t	i;
	char	*new_b;

	i = 0;
	new_b = NULL;
	while (((*b_read)[i] != '\n') && ((*b_read)[i] != '\0'))
		i++;
	if ((*b_read)[i] == '\n')
	{
//		++i;
		*line = ft_substr((*b_read), 0, i++);
//		new_b = ft_strdup(&(*b_read)[i]);
//		++i;
//		new_b = ft_strdup((*b_read) + i);
		new_b = ft_substr((*b_read), i, ft_sstrlen(*b_read) - i);
	}
	else
		*line = ft_strdup(*b_read);
	ft_scott_free(b_read, 0);
	return (new_b);
}

ssize_t	read_file(char **line, char **b, char **b_read, int fd)
{
	char	*temp;
	ssize_t	n;

	n = 1;
	while (!ft_strchr(*b_read, '\n') && n)
	{
		n = read(fd, *b, 16);
		(*b)[n] = '\0';
		temp = *b_read;
		*b_read = ft_strjoin(temp, *b);
		free(temp);
	}
	ft_scott_free(b, 0);
	*b_read = get_line(line, b_read);
	if (**line == '\0')
		ft_scott_free(line, 0);
	return (n);
}

int	ft_gnl(char **line, int fd)
{
	static char		*b_read = NULL;
	char			*b;
	ssize_t			n;

	if (fd < 0)
		return (-1);
	b = (char *)ft_memalloc(sizeof(char) * 17);
	if (!b)
		return (-1);
	if (read(fd, b, 0) < 0)
		ft_scott_free(&b, -1);
	if (!b_read)
		b_read = ft_strdup("");
	n = read_file(line, &b, &b_read, fd);
	if (n == 0 && !*line)
		return (0);
	return (1);
}


