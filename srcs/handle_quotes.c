/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:51:24 by me                #+#    #+#             */
/*   Updated: 2022/01/24 03:29:37 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// possibly rename?

#include "minishell.h"

int	count_strtab(char **tab)
{
	int	i;

	if (!tab)
		return (-1);	// or shoult it be 0?
	i = 0;
	while (tab[i])
		++i;
	return (i);
}

	// yea this is pretty pointless...
/*
char	**alloc_empty_strtab_n(int size)
{
	char **ret;

	if (size < 1)
		return (NULL);
	ret = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	return (ret);
}
*/

	// this might be the ugliest solution, ideally change
		// not necessary if use Tokens but for now i don't
	// could add to minilib?
	// do i want to keep the add?
int	dup_longer_strtab(char **tab, int add)
{
	int	i;
	int	len;
	char **tmp;

	if (!tab)
		return (-1);	// -1? would 0 be better?
	len = count_strtab(tab);
//	tmp = alloc_empty_strtab_n(len + add + 1);
	tmp = (char **)ft_memalloc(sizeof(char *) * (len + add + 1));
	if (!tmp)
		return (-1);
	i = 0;
	while (i < len)
	{
		tmp[i] = ft_strdup(tab[i]);
		if (!tmp[i])
		{
			ft_free_strtab(tmp);	// could put in the return if fine with dif ret val
			return (-1);
		}
		++i;
	}
	ft_free_strtab(tab);
	tab = tmp;
	return (len + 1);
}

	// unused for now...
	// shit, this isn't actually what i wanted...
int	add_back_strtab(char **tab, char *str)
{
	int	last;

	if (!tab || !str)
		return (0);	// yea i think 0 would be clear
	last = dup_longer_strtab(tab, 1);
	if (last == -1)
		return (0);
	tab[last] = str;	// so we don't do the substrhere? i think no
	return (1);			// cuz you don't know I'll want to add.
}

// this is basically like my special strjoin i made for GNL

	// should i really be freeing in the func
	// i mean if it goes well or pourly i free after right?
		// no because i ret t1 or t2 direct sometimes...
	// could i dup them instead and then free both outside either way?
		// would be more annoying i think to use...
char	**concat_strtabs(char **t1, char **t2)
{
	int		size;
	char	**ret;
	int		a;
	int		b;
	char	*tmp;

//	printf("concat_strtabs, start\n");
//	ft_print_strtab(t1);
//	ft_print_strtab(t2);
//	printf("concat_strtabs, done printing tabs\n");
	// holy shit this is getting a bit confusing...
	if (!t1 && !t2)
		return (NULL);
	if (!t1 || !*t1)
		return (t2);
	if (!t2 || !*t2)
		return (t1);

//	printf("concat_strtabs, after first conditions\n");
	size = count_strtab(t1) + count_strtab(t2);
	ret = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	a = 0;
//	printf("concat_strtabs, about to fill from first strtab\n");
	while (t1[a])
	{
//		printf("concat_strtabs, 1st strtab loop\n");
		tmp = ft_strdup(t1[a]);
		if (!tmp)
		{
//			printf("concat, 1st tab, dup failed\n");
			ft_free_strtab(t1);
			ft_free_strtab(t2);
			ft_free_strtab(ret);
			return (NULL);
		}
//		printf("concat_strtabs, 1st strtab loop, adding to ret[a]\n");
		ret[a] = tmp;
		++a;
	}
//	printf("concat_strtabs, about to fill from second strtab\n");
	b = 0;
	while (t2[b])
	{
		tmp = ft_strdup(t2[b]);
		if (!tmp)
		{
			ft_free_strtab(t1);
			ft_free_strtab(t2);
			ft_free_strtab(ret);
			return (NULL);
		}
		ret[a] = tmp;
		++a;
		++b;
	}
//	printf("concat_strtabs, done filling from tabs, end\n");
	ft_free_strtab(t1);
	ft_free_strtab(t2);
	return (ret);
}

	// so here we look for the next " or ' and grab all that and dup it into words
		// but make sure not after a pipe
int	wordify_quotes(char *line, char **words)
{
	int		last;
	int		next_pipe;
	int		next_quote;

//	printf("start of Wordify Quotes\n");
	if (!line || !words)
		return (1);
	next_pipe = ft_findchar(line, '|');
	next_quote = ft_findchar(&line[1], line[0]) + 1;
	if (next_quote ==  -1)
		return (1);
	if (next_pipe >= 0 && next_pipe < next_quote)
		return (1);		// something else? // this means there's a loose quote somewhere

	// this way just seems more complicated, for no particular reason...
/*
	char	*tmp;

	tmp = ft_substr(line, 0, next_quote);
	if (!tmp)
		return (1);
	if (!add_back_strtab(words, tmp))
		return (ft_scott_free(&tmp, 1));
*/

	last = dup_longer_strtab(words, 1);
	if (last == -1)
		return (1);
	words[last] = ft_substr(line, 0, next_quote);
	if (!words[last])	// i dont think i need to free.
		return (1);

//	printf("end of Wordify Quotes\n");
	return (0);
}




