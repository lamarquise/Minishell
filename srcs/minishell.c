/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:32:06 by me                #+#    #+#             */
/*   Updated: 2022/01/17 23:58:05 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	// here we do processing, like Lexer and Parser, then hand off to right func
		// either builtin or exec
int	run_mini(t_sh *all, char **line)
{

	(void)all;
	(void)line;

	// first check builtins
	// then run as a normal func
	return (1);
}

	// this ft is just about reading new lines
	// prolly not env, i would rather store env in the giant main struct
		// whatever that is called
int	minishell(t_sh *all, int i)
{
	char	*line;
	int		ret;

	(void)all;
	ft_prompt();
	ret = ft_gnl(&line, 0);
	printf("%s\n", line);

	// some sort of lexer parser that will turn the line into something useful
		// it will store all that shit in all?
		// in a linked list in all?
	ret = lexer(all, line);
	if (ret != 0)
	{
		
		// a custome free that checks if free possible?
		// free more stuff?
		free(line);
		return (ret);
	}

	// some sort of run or exec func that will execute everything
		// either it runs a builtin or does exec

	free(line);

	// ideally free everything in t_sh *all that only exists for this line of commands

	if (i == 3)		// i is just for testing
		return (-1);
	// retuns a status, not sure what the status should be...
	return (1);
}



int	main(int ac, char **av, char **env)
{
	int		status;
	t_sh	all;
	char	**envir;
	// so i call the lexer -> parser -> expander -> exectuor
	// nto sure what many of those are...

	if (ac != 1)
		return (0);
	(void)av;
	(void)env;
	(void)envir;
	// sort out sigaction redirects

	// init some stuff based on env

	// run the minishell loop 
	status = 0;	// why 0 i'm not sure...
	int i = 0;	// i is just for testing...
	// we keep status != -1 cuz if a positive error, the loop continues
	// but we print an error message being like yo, the input you put don't work...
	while (status != -1)
	{
		status = minishell(&all, i);		// sending env for now, will prolly change
		++i;
	}

//	ft_prompt();
//	ft_simple_print();

	// free shit
	// return the right thing, some sort of status i guess.
	return (0);
}
