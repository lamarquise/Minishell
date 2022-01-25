/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:50:26 by me                #+#    #+#             */
/*   Updated: 2022/01/25 04:53:07 by me               ###   ########.fr       */
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

// could make a fill_cmd_elem
	// basically everything in the if condition forest bolow
	// each if calls this func 1ce


	// this one leaves **words empty
int	simple_create_cmd_elem(t_input_line *input)
{
	int		ret;
	t_cmd	*new;
	
	if (!input)
		return (1);

	new = cmd_new(input, NULL);
	if (!new)
		return (1);	// returns 1! Perfect!
	ret = cmd_add_front(&input->cmds, new);
	if (ret != 0)
	{
		// is this the right place to free cmds? i guess?
		cmd_del_all(&input->cmds);
		return (1);
	}
	return (0);
}


	// honestly i might not even use this
	// if i'm creating cmd's before having words...
int	create_cmd_elem(t_input_line *input, char **words)
{
	int		ret;
//	char	**tmp;
	t_cmd	*new;
	
	if (!input || !words)
		return (1);

//	tmp = strtab_dup(words);

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
	int		ret;	// unused?
	int		next_split;
	char 	**words;
	char	**tmp;

	if (!input)
		return (1);	// i think the correct error is 1

	printf("-----------\nstart of lexer\n");

	words = NULL;	// you need this shit, it fixes everything
	tmp = NULL;
	ret = 0;
	pos = 0;
//	printf("in lexer, line: |%s|, next_pipe val: %d\n", input->line, next_pipe);
	if (simple_create_cmd_elem(input) == 1)
		return (1);
	while (input->line[pos])
	{
		next_split = ft_find_chars(&input->line[pos], "|\'\"");
		printf("lexer, in big loop, pos=%d, next_split=%d\n", pos, next_split);
		if (input->line[pos] == '\'' || input->line[pos] == '\"')
		{
//			printf("lexer, first char is \' or \", strtab before wordify:\n-----\n");
			// some sort of handle quotes that rets pos of last quote
			input->cmds->words = wordify_quotes(&input->line[pos], input->cmds->words);
			printf("lexer, strtab after wordify:\n---\n");
			ft_print_strtab(input->cmds->words);
			printf("---\n");
			if (!input->cmds->words)
				return (1);	// frees above?
	//		input->cmds->words = concat_strtabs(input->cmds->words, tmp);
	//		if (!input->cmds->words)
	//			return (1);	// there must be a better way of doing this...
			next_split = ft_strlen(input->cmds->words[strtab_len(input->cmds->words) - 1]);	// so add it to pos at the end.
		}
		else if (next_split == -1)	// if this happens the loop should end.
		{	// first we handle if there are no special chars
			printf("lexer, no quotes or |, printing strtab:\n---\n");
			tmp = ft_split(&input->line[pos], " \t\n");
			ft_print_strtab(tmp);
			if (!tmp)
				return (1);
//			printf("lexer, did the split\n");
			input->cmds->words = concat_strtabs(input->cmds->words, tmp);
			if (!input->cmds->words)
				return (1);	// there must be a better way of doing this...
//			printf("lexer, concated strtabs\n");
/*
			ret = create_cmd_elem(input, input->cmds->words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
*/
			// could make this next_split = ...
				// then no need for if at end of loop
			pos = ft_strlen(input->line);
//			printf("lexer, end of no pipe or quotes\n");
		}
		else if (input->line[next_split] == '|')
		{ // here we have a there's only a pipe section

			printf("lexer, there is a pipe\n");
				// next_split - 1?
			tmp = split_until(&input->line[pos], " \t\n", next_split - 1);
			if (!tmp)
				return (1);
			input->cmds->words = concat_strtabs(input->cmds->words, tmp);
			if (!input->cmds->words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?
			if (simple_create_cmd_elem(input) == 1)
				return (1);
			++next_split;
/*
			ret = create_cmd_elem(input, input->cmds->words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
*/
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
			input->cmds->words = concat_strtabs(input->cmds->words, tmp);
			if (!input->cmds->words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?

/*			ret = create_cmd_elem(input, input->cmds->words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
*/
		}
		else if (input->line[next_split] == '\'')
		{	// then we have a '' section
			printf("lexer, there is a \'\n");
				// next_split - 1?
			tmp = split_until(&input->line[pos], " \t\n", next_split - 1);
			if (!tmp)
				return (1);
			input->cmds->words = concat_strtabs(input->cmds->words, tmp);
			if (!input->cmds->words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?
/*
			ret = create_cmd_elem(input, input->cmds->words);
			if (ret != 0)
			{
				// no frees i think cuz already free in create_cmd_elem()
				return (1);
			}
*/
		}
// THE BOTOM 2 conditions are identical, you can make them 1
		// + 1?
		if (next_split >= 0)
			pos += next_split;
	}

/*
	// from when i was creating cmds after i filled a **words tab
	ret = create_cmd_elem(input, words);
	if (ret != 0)
	{
		// no frees i think cuz already free in create_cmd_elem()
		return (1);
	}
*/

	printf("-----\nvery end of lexer, pos=%d\n----------\n", pos);
//	ft_print_strtab(input->cmds->words);
	return (0);
}


