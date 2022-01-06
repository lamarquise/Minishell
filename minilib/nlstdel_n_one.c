/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlstdel_n_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:36:48 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 20:44:57 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	n_is_zero(t_nlist **lst)
{
	t_nlist	*tmp;

	tmp = (*lst)->next;
	free((*lst)->content);
	free(*lst);
	*lst = tmp;
}

int	ft_nlstdel_n_one(t_nlist **lst, int n)
{
	t_nlist	*tmp;
	t_nlist	*elem;

	if (!lst || !*lst || n < 0)
		return (0);
	tmp = NULL;
	if (n == 0)
		n_is_zero(lst);
	else
	{
		tmp = *lst;
		while (tmp && tmp->index < n - 1)
			tmp = tmp->next;
		elem = tmp->next;
		free(elem->content);
		tmp->next = elem->next;
		free(elem);
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmp->index -= 1;
		tmp = tmp->next;
	}
	return (1);
}
