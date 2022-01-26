/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:32:06 by me                #+#    #+#             */
/*   Updated: 2022/01/26 15:04:14 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// almost certainly put somewhere else...
int	create_input_line_elem(t_sh *all, char *line)
{
	t_input_line	*input;

	if (!all)
		return (1);
	// something about create a new cmd elem and add it to the list of cmds in sh
	input = input_line_new(all, line, ++all->n_hist);
	if (!input)
		return (1);
	if (input_line_add_front(&all->inputs, input) != 0)
	{
		// prolly free something too?
		// a bit over kill but for now 🤷
		input_line_del_all(&all->inputs);
		return (1);
	}
	return (0);
}


	// this ft is just about reading new lines
	// prolly not env, i would rather store env in the giant main struct
		// whatever that is called
int	minishell(t_sh *all, int i)
{
	char	*line;
	int		ret;

	ft_prompt();
	ret = ft_gnl(&line, 0);
//	printf("Printing line |%s|\n", line);

	ret = create_input_line_elem(all, line);
	if (ret != 0)
		return (ft_scott_free(&line, ret));
//	printf("in minishell func after create new cmd_line\n");

	ret = lexer(all->inputs);
	if (ret != 0)
	{
		// a custome free that checks if free possible?
		// free more stuff?

		// we don't want to free line cuz we keeping it in cmd_line struct.
//		free(line_input);
		return (ret);
	}
	
	print_all_cmd_strs(all->inputs->cmds);

/*	ret = parser(all->inputs);
	if (ret != 0)
	{
		// some sort of free?
		return (ret);
	}
*/

//	print_all_cmd_strs(all->inputs->cmds);

//	printf("in minishell func after lexer\n");

	// some sort of run or exec func that will execute everything
		// either it runs a builtin or does exec
	// could move this part but here for now

	printf("pre exec loop\n");
	ret = input_line_exec_loop(all->inputs);
	if (ret != 0)
	{
		// some sort of free
		return (ret);
	}
	printf("post exec loop\n");



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
	// so i call the lexer -> parser -> expander -> exectuor
	// nto sure what many of those are...

	if (ac != 1)
		return (1); // 1 right? or -1?
	all.ac = ac;
	all.av = av;
	all.envir = env;

	// should prolly secure later
	init_sh(&all);
//	builtin_env(&all);
	// sort out sigaction redirects

	// init some stuff based on env

	status = 0;	// why 0 i'm not sure...
	int i = 0;	// i is just for testing...
	// we keep status != -1 cuz if a positive error, the loop continues
	// but we print an error message being like yo, the input you put don't work...
	while (status != -1)
	{
		// don't forget to remove i
		status = minishell(&all, i);		// sending env for now, will prolly change
		++i;
	}
//	printf("main, before final free\n");
	free_sh(&all);
//	printf("main, after final free\n");

	// return the right thing, some sort of status i guess.
	return (0);
}
