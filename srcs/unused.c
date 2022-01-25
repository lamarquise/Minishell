/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <erlazo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:04:02 by erlazo            #+#    #+#             */
/*   Updated: 2022/01/25 17:04:18 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// unused atm
	// a candidate for the minilib
int	ft_times_appears(char *str, char sym)
{
	int	i;
	int	j;
	int	stop;

	//printf("in times appears, start\n");
	if (!str)
		return (0);
	i = 0;
	j = 0;
//	stop = ft_findchar(str, sym);
//	if (stop >= 0)
//		++j;
	stop = 0;
	// i fucking hate the new norm so GOD DAMN MUCH!!!!
		// this the ugliest stupidest way of making us do this!!!!
	printf("in times appears before loop, i=%d\n", i);
	while (stop >= 0)
	{
//		printf("in times appears loop, i=%d\n", i);
	//	++j;
		stop = ft_findchar(&(str[i]), sym);
		i += stop + 1;
		if (stop >= 0)
			++j;
	}
	return (j);
}


	// a good idea that i will maybe make later, but for now no need
/*
char	**strtab_dup(char **tab)
{
	char **ret;

	if (!tab || !*tab)	// i think this will make it easier in this program
		return (NULL);// don't want empty tables, like why bother
	ret = (char **)ft_memalloc(sizeof(char *)


}
*/
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
	// unused for now...
	// shit, this isn't actually what i wanted...
/*
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
*/


