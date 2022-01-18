/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:41:51 by me                #+#    #+#             */
/*   Updated: 2022/01/18 20:59:11 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	ft_print_full_list(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		ft_print_list_elem(lst);
		lst = lst->next;
	}
	return (1);
}
