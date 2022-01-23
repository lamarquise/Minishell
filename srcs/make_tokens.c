/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:57:19 by me                #+#    #+#             */
/*   Updated: 2022/01/23 06:16:44 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// possibly change name of file, possibly put these in lexer.c


// No idea if any of this works or does what it's supposed to...



	// this func might not work...
// possibly move this & possibly add to minilib
int	str_contains_only(char *str, char *set)
{
	int	i;
	int	found;

	if (!str)
		return (0);
	if (!set)
		return (1);
	i = 0;
	while (str[i])
	{
		found = ft_findchar(set, str[i]);
		if (found == -1)
			return (0);
		++i;
	}
	return (1);	// in this case 1 is good
}


// this will be sent a string and figure out what kind of token to create and
	// create it
// or should i send the return of the split direct?
int	add_token(t_cmd *cmd, char **words)
{
	// ok all this shit needs to change prolly
	int			i;
	char		*word;
	t_tok		*tmp;
	t_e_type	type;

	if (!cmd || !words)
		return (1);	// 1 i think
	// not sure about this second part...
	if (!*words)
		return (0);
	i = 0;
	while (words[i])
	{
		word = ft_strdup(words[i]);
		if (!word)
			return (1);
		if (!ft_strcmp(words[i], "<"))
		{
			// at this point do i even need to copy < to the token?
			type = RIN;
		}
		else if (!ft_strcmp(words[i], ">"))
			type = ROUT;
		else if (!ft_strcmp(words[i], "<<"))
			type = HDOC;
		else if (!ft_strcmp(words[i], ">>"))
			type = AROUT;
		else if (!ft_strcmp(words[i], "|"))		// no idea if i'll actually need this
			type = PIPE;
		else
			type = WORD;	// i doubt this is good enough
			// cuz in theory words are a-Z and _
	// should i have another func that checks if its a works in parenthesies?
	// or should the validity of the word be down the function we pass things to?


		tmp = toknew(type, word);
		if (!tmp)
			return (ft_scott_free(&word, 1));	// 1 i think
		if (tokadd_front(&cmd->tokens, tmp))
		{
			free(tmp);
			// will it work in this order?
			return (ft_scott_free(&word, 1));	// 1 i think
			//return (1);
		}
		++i;
	}


	return (0);
}





