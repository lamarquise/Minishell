/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:11:09 by me                #+#    #+#             */
/*   Updated: 2022/01/19 18:31:54 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// free everything

// a free for all in case shit goes wrong
// a free for just the stuff in t_sh *all for after an input line has been executed
// prolly other shit.

int free_sh(t_sh *all)
{
	if (!all)		// once again, is this necessary?
		return (1);
//	printf("in free_sh start\n");
	ft_lstclear(&all->env, &ft_lstdel_str_elem);	// returns void.
//	printf("in free_sh mid\n");
	ft_cmdline_del_all(&all->lines);	// secure this?
//	printf("in free_sh end\n");

    return (0);
}
