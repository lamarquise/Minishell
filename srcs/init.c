/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:16:02 by me                #+#    #+#             */
/*   Updated: 2022/01/23 06:16:57 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


	// maybe move later?
	// t_list for now...
	// ok less generic but we know more from the return...
int	ft_get_all_env(t_sh *all)
{
	int		i;
	char	*str;
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
		str = ft_strdup((all->envir)[i]);
		if (!str)
			return (3);	// nothing to free i think
		tmp = ft_lstnew(str);
		if (!tmp)
		{
			// anything to free?
			ft_scott_free(&str, 4);	// could put in return
			return (4);
		}
		ft_lstadd_front(&all->env, tmp);
		// can't secure cuz returns void right?
		++i;
	}
	return (0);
}

	// technicall some initing will have already happened.
int	init_sh(t_sh *all)
{
	if (!all)	// is this shit really necessary?
		return (1);

	all->n_hist = 0;
//	all->env = ft_get_all_env(void);
	if (ft_get_all_env(all) > 0)
	{
		// we call a func that generates some basic and generic env vars?
		// if we want...
		// like CD, HOME, shit like that?
		// is that unnecessary?
	}
	all->inputs = NULL;

	return (0);	// 0 is success, throughout entire program
}

