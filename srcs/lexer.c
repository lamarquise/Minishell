/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:50:26 by me                #+#    #+#             */
/*   Updated: 2022/01/26 20:44:08 by me               ###   ########.fr       */
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
	ret = cmd_add_back(&input->cmds, new);
	if (ret != 0)
	{
		// is this the right place to free cmds? i guess?
		cmd_del_all(&input->cmds);
		return (1);
	}
	return (0);
}



// could call this Parser if call "Parser.c" post processing of words or something
	// but at least it works
// the work of the Lexer is to identify tokens
	// send just the line?
// if lexer return (1) does that mean minishell should exit?
	// like in theory most ret 1s are for if a malloc fails right? meaing the whole thing should
	// free and quit, right?
int	lexer(t_input_line *input)
{
	int		pos;
	int		ret;	// unused?
	int		next_split;
	char	**tmp;
	t_cmd	*cur_cmd;	// MAKE SURE IF FAILURE YOU FREE INPUTS->CMD!!!!!

	if (!input)
		return (1);	// i think the correct error is 1

//	printf("-----------\nstart of lexer\n");

	tmp = NULL;
	ret = 0;
	pos = 0;
//	printf("in lexer, line: |%s|, next_pipe val: %d\n", input->line, next_pipe);
	if (simple_create_cmd_elem(input) == 1)
		return (1);
	cur_cmd = input->cmds;
	while (input->line[pos])
	{
		next_split = ft_find_chars(&input->line[pos], "|\'\"");
//		printf("lexer, in big loop, pos=%d, next_split=%d\n", pos, next_split);
		if (input->line[pos] == '\'' || input->line[pos] == '\"')
		{
			// addes the stuff in quotes to end of words strtab
			cur_cmd->words = wordify_quotes(&input->line[pos], cur_cmd->words);
//			printf("lexer, strtab after wordify:\n---\n");
//			ft_print_strtab(cur_cmd->words);
//			printf("---\n");
			if (!cur_cmd->words)
				return (1);	// frees above?
			next_split = ft_strlen(cur_cmd->words[strtab_len(cur_cmd->words) - 1]);	// so add it to pos at the end.
		}
		else if (next_split == -1)	// if this happens the loop should end.
		{	// first we handle if there are no special chars
//			printf("lexer, no quotes or |, printing strtab:\n---\n");
			tmp = ft_split(&input->line[pos], " \t\n");
//			ft_print_strtab(tmp);
			if (!tmp)
				return (1);
//			printf("lexer, did the split\n");
			cur_cmd->words = concat_strtabs(cur_cmd->words, tmp);
			if (!cur_cmd->words)
				return (1);	// there must be a better way of doing this...
//			printf("lexer, concated strtabs\n");

			// could make this next_split = ...
				// then no need for if at end of loop
			pos = ft_strlen(input->line);
//			printf("lexer, end of no pipe or quotes\n");
		}
		else if (input->line[pos + next_split] == '|')
		{ // here we have a there's only a pipe section

//			printf("lexer, there is a pipe\n");
				// next_split - 1?
			tmp = split_until(&input->line[pos], " \t\n", next_split - 1);
			if (!tmp)
				return (1);
			cur_cmd->words = concat_strtabs(cur_cmd->words, tmp);
			if (!cur_cmd->words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?
			if (simple_create_cmd_elem(input) == 1)
				return (1);
			cur_cmd = cur_cmd->next;
			++next_split;
		}
		else if (input->line[pos + next_split] == '\"' || input->line[pos + next_split] == '\'')
		{	// then we have a "" section
			// THIS ABSOLUTELY DOES NOT WORK BUT NOT SURE WHAT TO DO
			// TESTING THE REST FOR NOW...
//			printf("lexer, there is a \"\n");
				// next_split - 1?
			tmp = split_until(&input->line[pos], " \t\n", next_split - 1);
			if (!tmp)
				return (1);
			cur_cmd->words = concat_strtabs(cur_cmd->words, tmp);
			if (!cur_cmd->words)
				return (1);	// there must be a better way of doing this...
			// normal split until around spaces and shove in a new t_cmd
			// do we process the cmd now?

		}
		// + 1?
		if (next_split >= 0)
			pos += next_split;
	}

//	printf("-----\nvery end of lexer, pos=%d\n----------\n", pos);
//	ft_print_strtab(cur_cmd->words);
	return (0);
}


