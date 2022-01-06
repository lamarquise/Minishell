/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:44:54 by ericlazo          #+#    #+#             */
/*   Updated: 2021/12/10 09:01:52 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	ft_findchar(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((char)*s1 && (char)*s2 && (char)*s1 == (char)*s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

size_t	ft_strlen(const char *s)
{
	size_t		a;

	a = 0;
	if (s)
	{
		while (s[a])
			++a;
	}
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	a;
	unsigned char	*str;

	a = 0;
	str = s;
	while (a < n)
	{
		str[a] = '\0';
		++a;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*tmp;

	tmp = (char *)s;
	a = 0;
	while (tmp[a] || (tmp[a] == '\0' && (char)c == '\0'))
	{
		if (tmp[a] == (char)c)
			return (&tmp[a]);
		++a;
	}
	return (NULL);
}
