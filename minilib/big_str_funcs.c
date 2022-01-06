/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_str_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:48:26 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 20:14:24 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*ret;

	a = 0;
	if (!s)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + a] && a < len)
		{
			ret[a] = (char)s[start + a];
			++a;
		}
	}
	ret[a] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*ret;

	if (!s1)
		return (NULL);
	a = 0;
	while (s1[a])
		++a;
	ret = ft_memalloc(sizeof(char) * (a + 1));
	if (!ret)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		ret[a] = s1[a];
		++a;
	}
	return (ret);
}

char	*ft_fill_with(char this, int len)
{
	char	*ret;
	int		i;

	if (!this || len < 1)
		return (NULL);
	ret = ft_memalloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = this;
	ret[i] = '\0';
	return (ret);
}

void	*ft_memalloc(size_t size)
{
	unsigned int	a;
	char			*ret;

	a = 0;
	ret = (char *)malloc(sizeof(void) * size);
	if (!ret)
		return (NULL);
	while (a < size)
	{
		ret[a] = '\0';
		++a;
	}
	return ((void *)ret);
}
