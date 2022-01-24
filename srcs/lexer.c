/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:50:26 by me                #+#    #+#             */
/*   Updated: 2022/01/24 03:29:35 by me               ###   ########.fr       */
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

int	create_cmd_elem(t_input_line *input, char **words)
{
	int		ret;
	t_cmd	*new;
	
	if (!input || !words)
		return (1);
	new = cmd_new(input, words);
	if (!new)
		return (ft_free_strtab(words));	// returns 1! Perfect!
	ret = cmd_add_front(&input->cmds, new);
	if (ret != 0)
	{
		// is this the right place to free cmds? i guess?
		cmd_del_all(&input->cmds);
		return (ft_free_strtab(words));	// returns 1! Perfect!
	}
	// this is where you might call a create_tokens_list()
		// func to go throught the words and sort them out...
	// or maybe do that in the lexer func, idk
	return (0);
}

// the work of the Lexer is to identify tokens
	// send just the line?
int	lexer(t_input_line *input)
{
	int		pos;
//	int next_pipe;	// these values are possitions relative to cur pos of pos value
//	int	next_quote;
	int		ret;
	int		next_split;
	char 	**words;
	char	**tmp;

	if (!input)
		return (1);	// i think the correct error is 1

	printf("start of lexer\n");

	words = NULL;	// you need this shit, it fixes everything
	tmp = NULL;
	pos = 0;
//	printf("in lexer, line: |%s|, next_pipe val: %d\n", input->line, next_pipe);
	while (input->line[pos])
	{
		printf("lexer, in big loop\n");
		next_split = ft_find_chars(&input->line[pos], "|\'\"");
		if (input->line[pos] == '\'' || input->line[pos] == '\"')
		{
			printf("lexer, first char is \' or \"\n");
			// some sort of handle quotes that rets pos of last quote
			ret = wordify_quotes(&input->line[pos], tmp);
			if (ret == -1)
				return (1);	// frees above?
			words = concat_strtabs(words, tmp);
			if (!words)
				return (1);	// there must be a better way of doing this...
			next_split = ret;	// so add it to pos at the end.
		}
		else if (next_split == -1)	// if this happens the loop should end.
		{	// first we handle if there are no special chars
			printf("lexer, no quotes or |\n");
			tmp = ft_split(&input->line[pos], " \t\n");
			ft_print_strtab(tmp);
			if (!tmp)
				return (1);
//			printf("lexer, did the split\n");
			words = concat_strtabs(words, tmp);
			if (!words)
				return (1);	// there must be a better way of doing this...
//			printf("lexer, concated strtabs\n");
			ret = create_cmd_elem(input, words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
//			printf("lexer, end of no pipe or quotes\n");
		}
		else if (input->line[next_split] == '|')
		{ // here we have a there's only a pipe section

			printf("lexer, there is a pipe\n");
				// next_split - 1?
			tmp = split_until(&input->line[pos], " \t\n", next_split - 1);
			if (!tmp)
				return (1);
			words = concat_strtabs(words, tmp);
			if (!words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?
			ret = create_cmd_elem(input, words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
		}
		else if (input->line[next_split] == '\"')
		{	// then we have a "" section
			// THIS ABSOLUTELY DOES NOT WORK BUT NOT SURE WHAT TO DO
			// TESTING THE REST FOR NOW...
			printf("lexer, there is a \"\n");
				// next_split - 1?
			tmp = split_until(&input->line[pos], " \t\n", next_split - 1);
			if (!tmp)
				return (1);
			words = concat_strtabs(words, tmp);
			if (!words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?
			ret = create_cmd_elem(input, words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
		}
		else if (input->line[next_split] == '\'')
		{	// then we have a '' section
			printf("lexer, there is a \'\n");
				// next_split - 1?
			tmp = split_until(&input->line[pos], " \t\n", next_split - 1);
			if (!tmp)
				return (1);
			words = concat_strtabs(words, tmp);
			if (!words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?
			ret = create_cmd_elem(input, words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
		}
		// + 1?
		pos += next_split;
	}

	printf("very end of lexer:\n");
	ft_print_strtab(words);
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

