/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 05:33:20 by me                #+#    #+#             */
/*   Updated: 2022/01/23 22:22:39 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

    // to some degree this inits too
t_cmd	*cmd_new(t_input_line *input, char **words)
{
	t_cmd	*elem;

	elem = (t_cmd *)malloc(sizeof(t_cmd));
	if (!elem)
		return (NULL);
	elem->tokens = NULL;
	elem->words = words;
	elem->sqs = 0;
	elem->dqs = 0;
	elem->pipe[0] = 0;	// no idea if these are the right defualt values
	elem->pipe[1] = 1;	// i think one should be STDIN and other STDOUT
	elem->home_inp = input;
	elem->next = NULL;
	return (elem);
}

int	cmd_add_front(t_cmd **lst, t_cmd *new)
{
	if (!lst || !new)
		return (1);
	new->next = *lst;
	*lst = new;
	return (0);
}

int	cmd_del_all(t_cmd **lst)
{
	t_cmd	*tmp;

	if (!lst)
		return (1);
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_free_strtab((*lst)->words);
//		ft_scott_free(&(*lst)->words, 0);
        tokdel_all(&(*lst)->tokens); // secure?
		(*lst)->home_inp = NULL;	// prolly not necessary
		free(*lst);
		*lst = tmp;
	}
	return (0);
}
