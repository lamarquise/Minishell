/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:37:12 by me                #+#    #+#             */
/*   Updated: 2022/01/25 18:32:15 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt(void)
{
//	write(1, "➜ minishell > ", 14);
	ft_putstr_fd("➜ minishell > ", 1);	// fd 1 works just fine, not sure
										// why it didn't before
	//ft_putstr_fd("➜ minishell > ", 2);	// fd 2 works but it's STDERR
//	ft_putstr_fd("➜ minishell > ", 3);	// fd 3 absolutely does not work
}


	// no in final program i think
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
