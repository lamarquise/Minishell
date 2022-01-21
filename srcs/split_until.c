/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_until.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:49:25 by me                #+#    #+#             */
/*   Updated: 2022/01/21 18:56:40 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// possibly a contender for being added to minilib

char	**split_until(char const *s, char *set, int l)
{
	char *str;
	char **ret;

	// need a condition for if l is neg or something 
	if (!s || !set)
		return (NULL);
	str = ft_substr(s, 0, l);
	if (!str)
		return (NULL);
	ret = ft_split(str, set);
	ft_scott_free(&str, 1);
    return (ret);
}

// seems like it would be quite difficult to modify...
/*
static int	ft_check_set(char *set)
{
	int	i;
	int	j;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		j = i + 1;
		while (set[j])
		{
			if (set[i] == set[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static int	ws(char *s, char *set)
{
	int		a;
	int		words;

	a = 0;
	words = 0;
	if (!s)
		return (1);
	while (s[a])
	{
		if ((ft_findchar(set, s[a])) < 0 \
			&& ((ft_findchar(set, s[a + 1])) >= 0 \
			|| s[a + 1] == '\0'))
			++words;
		++a;
	}
	return (words + 1);
}

static int	wl(char *s, int start, char *set)
{
	int		a;

	a = 0;
	if (!s)
		return (1);
	while (s[start + a] && (ft_findchar(set, s[start + a])) == -1)
		++a;
	return (a + 1);
}

int	fill_ret(char **ret, char const *s, char *set, int a)
{
	int		b;
	int		d;

	if (!ret || !s)
		return (-1);
	b = 0;
	while ((char)s[a])
	{
		if ((char)s[a] && (ft_findchar(set, (char)s[a])) >= 0)
			++a;
		else
		{
			d = 0;
			ret[b] = ft_memalloc(sizeof(char) * wl((char *)s, a, set));
			if (!ret[b])
				return (-1);
			while ((char)s[a] && (ft_findchar(set, (char)s[a])) == -1)
				ret[b][d++] = s[a++];
			ret[b++][d] = '\0';
		}
	}
	return (b);
}

    // use a size_t? i mean i way prefer ints...
    // will the norm let me call it len?
char	**split_until(char const *s, char *set, int l)
{
	int		a;
	int		b;
	char	**ret;

    // so we are saying, if l = 0 we still malloc a think, and
    // that thing is empty and that's fine
    // seems like acceptable behavior.
	// yea seems good cuz if nothing it won't tell the program to abort
	// we can check if the malloced thing is empty
	if (!s || !ft_check_set(set) || l < 0)
		return (NULL);
	a = 0;
	b = 0;
	ret = (char **)ft_memalloc(sizeof(char *) * ws((char *)s, set, l));
	if (!ret)
		return (NULL);
	b = fill_ret(ret, s, set, a);
	if (b == -1)
	{
		ft_free_strtab(ret);
		return (NULL);
	}
	return (ret);
}
*/
