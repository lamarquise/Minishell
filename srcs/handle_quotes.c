/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:51:24 by me                #+#    #+#             */
/*   Updated: 2022/01/25 18:11:07 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// possibly rename?


#include "minishell.h"

int	strtab_len(char **tab)
{
	int	i;

	if (!tab)
		return (-1);	// or shoult it be 0?
	i = 0;
	while (tab[i])
		++i;
	return (i);
}


	// this might be the ugliest solution, ideally change
		// not necessary if use Tokens but for now i don't
	// could add to minilib?
	// do i want to keep the add?
char	**dup_longer_strtab(char **tab, int add)
{
	int	i;
	int	len;
	char **ret;

//	printf("Start of Dup_strtab, strtab:\n--\n");
//	ft_print_strtab(tab);
//	printf("--\n");
	if (!tab)
		return (NULL);	// -1? would 0 be better?
	len = strtab_len(tab);
//	ret = alloc_empty_strtab_n(len + add + 1);
	ret = (char **)ft_memalloc(sizeof(char *) * (len + add + 1));
	if (!ret)
	{
		ft_free_strtab(tab);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ret[i] = ft_strdup(tab[i]);
		if (!ret[i])
		{
			ft_free_strtab(tab);
			ft_free_strtab(ret);	// could put in the return if fine with dif ret val
			return (NULL);
		}
		++i;
	}
	ft_free_strtab(tab);
//	tab = ret;
//	printf("End of Dup_strtab, strtab:\n--\n");
//	ft_print_strtab(ret);
//	printf("--\n");
	return (ret);
}

// this is basically like my special strjoin i made for GNL

	// should i really be freeing in the func
	// i mean if it goes well or pourly i free after right?
		// no because i ret t1 or t2 direct sometimes...
	// could i dup them instead and then free both outside either way?
		// would be more annoying i think to use...
	// call it join_strtab?
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
	size = strtab_len(t1) + strtab_len(t2);
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

// maybe rework the Perview of this function, like maybe some of this could be done
	// in lexer?
// so here we look for the next " or ' and grab all that and dup it into words
		// but make sure not after a pipe
char	**wordify_quotes(char *line, char **words)
{
	int		last;
	int		next_quote;
	char	**ret;

//	printf("start of Wordify Quotes, strtab:\n--\n");
//	ft_print_strtab(words);
//	printf("--\n");
	if (!line || !words)
	{
		ft_free_strtab(words);
		return (NULL);
	}
	ret = NULL;
	// it dones't matter if there 's a pipe in quotes!!!!!!!!!!!!!
//	next_quote = ft_findchar(&line[1], line[0]) + 1;
	next_quote = ft_findchar(&line[1], line[0]);
//	printf("wordify, next_quote = %d\n", next_quote);

	// this may not be the expected behavior, sujet unclear, maybe i need to pass the bad arg to cmds
		// and they tell me they exist but args are bad.
	if (next_quote == -1)
	{
//		printf("wordify, didn't find 2nd quote, next_quote = %d\n", next_quote);
		ft_free_strtab(words);
		return (NULL);
	}
	ret = dup_longer_strtab(words, 1); //in theory if it fucks up i free the OG words in it so no leaks
	if (!ret)
	{
		// wait, if dup_strtab fails doesn't words get freed either way?
			// yes, at this point, words is freed.
//		ft_free_strtab(words);
		return (NULL);
	}
	last = strtab_len(words) + 1;
//	printf("Wordify after tab dup, strtab ret:\n--\n");
//	ft_print_strtab(ret);
//	printf("--\n");
	// + 2 cuz if str "hi there" we start findchar at hi there" and want to get past last "
	ret[last] = ft_substr(line, 0, next_quote + 2);
	if (!ret[last])	// i dont think i need to free.
	{
		// this works because if substr fails
		// nothing new gets allocated to ret, so when i free_strtab(ret)
			// it frees all the strings and the whole thing, no need to
			// worry about \0\0 being at the end, the whole thing gets freed.
		ft_free_strtab(ret);
		return (NULL);
	}
//	printf("*****\nnew quotes line: |%s|\n******\n", ret[last]);
//	printf("End of wordify, strtab:\n--\n");
//	ft_print_strtab(ret);
//	printf("--\n");

//	return (0);	// you idiot, not 0
	return (ret);
}




