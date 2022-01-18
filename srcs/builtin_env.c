/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:38:48 by me                #+#    #+#             */
/*   Updated: 2022/01/18 21:13:29 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_sh *all)
{
	// is this necessary?
	if (!all)
		return (1);
	ft_print_full_list(all->env);
	// assuming env is kept as a t_list for now

	return (0);
}
