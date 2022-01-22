/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_line_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:27:25 by me                #+#    #+#             */
/*   Updated: 2022/01/21 21:34:16 by me               ###   ########.fr       */
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
    elem->tokens = NULL;
    elem->dqs = 0;
    elem->sqs = 0;
	elem->home = all;
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

    // this is gonna be much trickier
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
        ft_tokdel_all(&(*lst)->tokens); // secure?
		free(*lst);
		*lst = tmp;
	}
	return (0);
}
