/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:59:16 by ericlazo          #+#    #+#             */
/*   Updated: 2022/01/24 18:42:28 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	ft_free_strtab(char **tab)
{
	int		a;

	a = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[a])
	{
		ft_scott_free(&(tab[a]), 1);
		++a;
	}
	return (1);
}

int	ft_print_strtab(char **tab)
{
	int		a;

	if (!tab)
		return (0);
	a = 0;
	while (tab[a])
	{
		write(1, tab[a], ft_strlen(tab[a]));
		write(1, "\n", 1);
		++a;
	}
	return (1);
}
