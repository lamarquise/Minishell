/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_line_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:27:25 by me                #+#    #+#             */
/*   Updated: 2022/01/23 05:32:52 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

    // to some degree this inits too
t_input_line	*input_line_new(t_sh *all, char *line, int num)
{
	t_input_line	*elem;

	elem = (t_input_line *)malloc(sizeof(t_input_line));
	if (!elem)
		return (NULL);
	elem->num = num;
	elem->line = line;
	elem->cmds = NULL;
	elem->home_sh = all;
	elem->next = NULL;
	return (elem);
}

int	input_line_add_front(t_input_line **lst, t_input_line *new)
{
	if (!lst || !new)
		return (1);
	new->next = *lst;
	*lst = new;
	return (0);
}

int	input_line_del_all(t_input_line **lst)
{
	t_input_line	*tmp;

	if (!lst)
		return (1);
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_scott_free(&(*lst)->line, 0);
        cmd_del_all(&(*lst)->cmds); // secure?
		(*lst)->home_sh = NULL;	// prolly not necessary
		free(*lst);
		*lst = tmp;
	}
	return (0);
}
