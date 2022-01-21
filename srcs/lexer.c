/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:50:26 by me                #+#    #+#             */
/*   Updated: 2022/01/21 20:32:46 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// diff name?
	// find_of_chars? like find the first of these?
// very possibly could add this to minilib
	// returns the pos of first one it finds
int	ft_find_chars(char *str, char *syms)
{
	int	i;
	int	j;

	if (!str || !syms)
		return (-1);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (syms[j])
		{
			if (str[i] == syms[j])
				return (i);
			++j;
		}
		++i;
	}
	return (-1);
}

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


	// better name?
	// just sending line, is that ok?
	// should i be calling t_cmd_line cmd rather than line everywhere?
/*
int	sort_out_quotes(t_cmd_line *cmd)
{
	int	i;

	if (!cmd)
		return (1);
	i = ft_find_chars(cmd->line, "\"\'");
	if (cmd->line[i] == '\'')
		cmd->sqs = 1;
	else if (cmd->line

	return (0);
}
*/


/*
	New idea for our lexing loop
	i figure out if there's a pipe with findchar
	then i look for ' or "
	then i split before ' or "
	grab all in ' or " and put in a token
	and look for ' or " again
	Repeat token part

*/

	// send just the line?
int	lexer(t_cmd_line *cmd)
{
	int pos;
	int next_pipe;	// these values are possitions relative to cur pos of pos value
	int	next_quote;
	int	split_until;
	char **tmp;

	if (!cmd)
		return (1);	// i think the correct error is 1

	pos = 0;
//	printf("in lexer, line: |%s|, next_pipe val: %d\n", cmd->line, next_pipe);
	while (cmd->line[pos])
	{
		// could i just do find_chars( | ' " )?
		next_pipe = ft_findchar(&cmd->line[pos], '|');
		next_quote = ft_find_chars(&cmd->line[pos], "\'\"");
/*		if (next_pipe > next_quote)
			split_until = next_quote;
		else
			split_until = next_pipe;
		// next_quote - 1?
		tmp = split_until(&cmd->line[pos], " \t\n", split_until - 1);
		if (!tmp)
			return (1);	// ret 1?
		// now we need a func that figures out what each tmp str is
		// and we put those in tokens with cor eneum value.
*/
		if (next_pipe > next_quote)
		{
			// next_quote - 1?
			tmp = split_until(&cmd->line[pos], " \t\n", split_until - 1);
			if (!tmp)
				return (1);	// ret 1?
			// now we need a func that figures out what each tmp str is
			// and we put those in tokens with cor eneum value.

			// and then we need to put the stuff in the quotes in the following token
		}

	}

	return (0);
}


// int?
	// ok so our lexer should identify tokens of first (aka top) elem of
		// t_cmd_line *lines in *all that it encounters
/*
// the old version
int	lexer(t_sh *all)
{
	if (!all || !all->lines)
		return (1);

//	printf("in lexer, start\n");
	// is this where we put line in the cmd_line struct?

	if (sort_out_quotes(all->lines) != 0)
	{
		// free some shit?
		return (2);
	}
	// ok so use a findchar to look for quotes
	int n_sqs;

	n_sqs = ft_times_appears(all->lines->line, '\'');
	printf("in lexer, times \' apprears in line: %d\n", n_sqs);

	return (0); // means all good
	// return (2); if parsing error!
	// return (-1); if need to exit out of minishell program
}
*/





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







