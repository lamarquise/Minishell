/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:50:50 by me                #+#    #+#             */
/*   Updated: 2022/01/26 02:09:11 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// some sort of parser?


// could call this post processing or something if call "lexer.c" parser instead
int	parser(t_input_line *input)
{
	int		ret;
	t_cmd	*tmp;

	if (!input || !input->cmds)
		return (1);


	// not sure what order to do things in so for now just adding them one at a time but make sure is
		// as flexible as possible so can move around

	// should all the calls be in a t_cmd loop, or some called outside?

	tmp = input->cmds;
	while (tmp)
	{
		ret = perform_expansions(tmp);
		if (ret != 0)
		{
			// free stuff?
			return (1);
		}

		tmp = tmp->next;
	}


	return (0);
}
