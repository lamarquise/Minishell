/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:16:02 by me                #+#    #+#             */
/*   Updated: 2022/01/18 21:16:05 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


	// maybe move later?
	// t_list for now...
	// ok less generic but we know more from the return...
int	ft_get_all_env(t_sh *all)
{
	int		i;
	t_list	*tmp;

	if (!all)
		return (1);
	if (!all->envir)
		return (2);
	// now what?
	// we cycle through all->envir creating a linked list which we add to all, sure.
	i = 0;
	tmp = NULL;
	// i dereference some shit?
	while ((all->envir)[i])
	{
		tmp = ft_lstnew((all->envir)[i]);
		ft_lstadd_front(&all->env, tmp);
		++i;
	}
	return (0);
}

	// technicall some initing will have already happened.
int	init_sh(t_sh *all)
{
	if (!all)	// is this shit really necessary?
		return (1);

	all->nhist = 0;
//	all->env = ft_get_all_env(void);
	if (ft_get_all_env(all) > 0)
	{
		// we call a func that generates some basic and generic env vars?
		// if we want...
		// like CD, HOME, shit like that?
		// is that unnecessary?
	}
	all->lines = NULL;

	return (0);	// 0 is success, throughout entire program
}

