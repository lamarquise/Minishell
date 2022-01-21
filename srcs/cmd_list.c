/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:27:25 by me                #+#    #+#             */
/*   Updated: 2022/01/21 20:32:54 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

    // to some degree this inits too
t_cmd_line	*ft_cmdline_new(t_sh *all, char *line, int num)
{
	t_cmd_line	*elem;

	elem = (t_cmd_line *)malloc(sizeof(t_cmd_line));
	if (!elem)
		return (NULL);
	elem->num = num;
	elem->line = line;
    elem->tokens = NULL;
    elem->dqs = 0;
    elem->sqs = 0;
	elem->home = all;
	elem->next = NULL;
	return (elem);
}

int	ft_cmdline_add_front(t_cmd_line **lst, t_cmd_line *new)
{
	if (!lst || !new)
		return (1);
	new->next = *lst;
	*lst = new;
	return (0);
}

    // this is gonna be much trickier
int	ft_cmdline_del_all(t_cmd_line **lst)
{
	t_cmd_line	*tmp;

	if (!lst)
		return (1);
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_scott_free(&(*lst)->line, 0);
        ft_tokdel_all(&(*lst)->tokens); // secure?
		free(*lst);
		*lst = tmp;
	}
	return (0);
}
