/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_hub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:51:28 by me                #+#    #+#             */
/*   Updated: 2022/01/24 16:58:37 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// acutally maybe this is where the builtin if tree can live.
// this will almost certainly be modified and turned into a file per builtin at least



// this is where we call one or another builtin func
	// obviously this is gona have to change, but it'a a place holder for now
int	builtin_triage(t_cmd *cmd)
{
	if (!cmd)
		return (1);

	// prolly gonna need to be more complex?
	if (ft_strcmp(cmd->words[0], "exit") == 0)
	{
		printf("in triage, exiting now\n");
		exit(0);
	}
	else
	{
//		printf("sorry builtin still under construction\n");
		// i don't think i'll handle it this way in the end but...
		return (-2);
	}

	return (0);
}
