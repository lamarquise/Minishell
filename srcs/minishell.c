/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:32:06 by me                #+#    #+#             */
/*   Updated: 2022/01/06 00:56:41 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	// here we do processing, like Lexer and Parser, then hand off to right func
		// either builtin or exec
int	run_mini(char **env, char **line)
{

	(void)env;
	(void)line;

	// first check builtins
	// then run as a normal func
	return (1);
}

	// this ft is just about reading new lines
int	minishell(char **env, int i)
{
	char	*line;
	int		ret;

	(void)env;
	ft_prompt();
	ret = ft_gnl(&line, 0);
	printf("%s\n", line);

	// would it be better to do the line processing here?
		// as in the Lexer and parse?
		// no do it in launch
	// this is the part where i can do stuff with line, like run the lexer...

	// if nothing we return?

	// if something we send to run_mini()

	free(line);

	if (i == 3)		// i is just for testing
		return (-1);
	// retuns a status, not sure what the status should be...
	return (1);
}



int	main(int ac, char **av, char **env)
{
	int	status;
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
	while (status != -1)
	{
		status = minishell(env, i);		// sending env for now, will prolly change
		++i;
	}

//	ft_prompt();
//	ft_simple_print();

	// free shit
	// return the right thing, some sort of status i guess.
	return (0);
}
