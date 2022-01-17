/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:23:29 by me                #+#    #+#             */
/*   Updated: 2022/01/17 20:25:05 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// everything to do with token lists


// will need a
	// new
	// add front
	// add back?
	// del first
	// del all?


t_tok	*ft_toknew(t_e_type type)
{
	t_tok	*elem;

	elem = (t_tok *)malloc(sizeof(t_tok));
	if (!elem)
		return (NULL);
	elem->type = type;
	elem->next = NULL;
	return (elem);
}

// fine for now
int	ft_tokadd_front(t_tok **lst, t_tok *new)
{
	if (!lst || !new)
		return (0);
	new->next = *lst;
	*lst = new;
	return (1);
}

int	ft_tokdel_all(t_tok **lst)
{
	t_tok	*tmp;

	if (!lst)
		return (0);
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	return (1);
}