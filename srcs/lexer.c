/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:50:26 by me                #+#    #+#             */
/*   Updated: 2022/01/19 05:47:03 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


	// a candidate for the minilib
int	ft_times_appears(char *str, char sym)
{
	int	i;
	int	j;
	int	stop;

	printf("in times appears, start\n");
	if (!str)
		return (0);
	i = 0;
	j = 0;
	stop = ft_findchar(str, sym);
//	if (i >= 0)
//		++j;
	// i fucking hate the new norm so GOD DAMN MUCH!!!!
		// this the ugliest stupidest way of making us do this!!!!
	printf("in times appears before loop, i=%d\n", i);
	while (stop >= 0)
	{
//		printf("in times appears loop, i=%d\n", i);
		++j;
		stop = ft_findchar(&(str[i + 1]), sym);
		i += stop + 1;
	}
	return (j);
}

// the work of the Lexer is to identify tokens

// how will it work?
/*
	ok so first we need to group things by quotes?
	let's start by assuming no quotes

	we split everythign around space \t and \n
		do we even really need \n?
	then we determin what each split thing is and add it to a linked list
		of tokens
*/

// int?
	// ok so our lexer should identify tokens of first (aka top) elem of
		// t_cmd_line *lines in *all that it encounters
int	lexer(t_sh *all)
{
	if (!all || !all->lines)
		return (1);

	printf("in lexer, start\n");
	// is this where we put line in the cmd_line struct?

	// ok so we go through the line, we split it around quotes?
	// ok what if first we go through and find quotes
	// then we split around quotes
	// then what's left we split around spaces

	// ok so use a findchar to look for quotes
	int n_sqs;

	n_sqs = ft_times_appears(all->lines->line, '\'');
	printf("lexer, times \' apprears in line: %d\n", n_sqs);

	return (0); // means all good
	// return (2); if parsing error!
	// return (-1); if need to exit out of minishell program
}








