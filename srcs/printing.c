/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:37:12 by me                #+#    #+#             */
/*   Updated: 2022/01/06 00:56:52 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt(void)
{
	ft_putstr_fd("➜ minishell > ", 2);
}


void	ft_simple_print()
{
	char	*line;
	int		ret;
	
	ft_prompt();
	(void)line;
	(void)ret;
	ret = ft_gnl(&line, 0);
//	while ((ret = ft_gnl(&line, 0)) > 0)
	while (ret)
	{
		//ft_putchar('\n');
		printf("%s\n", line);
		// i doubt this shit is secure...
		free(line);
		ft_prompt();
		ret = ft_gnl(&line, 0);
	}

	
}
