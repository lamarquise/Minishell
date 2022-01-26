/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <erlazo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:20:50 by erlazo            #+#    #+#             */
/*   Updated: 2022/01/26 15:02:18 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this gets called somewhere in parser
	// needs to be flexible so order can change
#include "minishell.h"


	// yes **concat_strtabs should definitly be called join_strtabs
//char	*concat_strab()

// basically the same as wordify but with diff split params? and not for a strtab, just one str.
char	*expandify_word(t_cmd *cmd, char *word)
{
	int		i;
	char	*ret;

	if (!cmd || !word)
		return (NULL);
	i = 0;
	ret = NULL;	

	return (ret);
}

	// only useful i keep env vars in t_list as "KEY=value" string.
//char	*extract_env_var_value()


// if wanted to make a expand_word() i could send it t_cmd cmd and int i
	// where i is cmd->words[i].
	// cmd->home_inp exists so can get access to env vars.

	// rename?
// we are assuming **words with quotes will still have the quotes in the str
	// so the idea is to replace not he whole **words tab, just the str in it
int	perform_expansions(t_cmd *cmd)
{
	int		i;
	int		pos;
	char	*tmp;

	// do we allow lower case char in $ENV vars?
	if (!cmd || !cmd->words)
		return (1);
	if (!*cmd->words)	// as in **words is not NULL but *words is, it's an empty tab
		return (0);		// or shoud i just be like nah we don't want that shit, delete it and the cmd?
	tmp = NULL;
	pos = 0;
	i = 0;
	while (cmd->words[i])
	{
		// here we look for $ and for "
		// need a way to be like skip this one if starts with '
		if (ft_findchar(cmd->words[i], '$'))
		{
			
		}

		++i;
	}

	return (0);
}
