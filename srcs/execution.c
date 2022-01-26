/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:14:19 by me                #+#    #+#             */
/*   Updated: 2022/01/26 15:04:45 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// absolutely needs a better name...


	// will need a lot of work to make up to 42 standards, this is a test versions
		// for now
	// is that what i want to  pass?
int execute_external(t_cmd *cmd)
{
	pid_t	pid;
	pid_t	wpid;	// not sure i'll need this one but who knows
	int		status;

	status = 0;

	if (!cmd)
		return (1);
	pid = fork();
	if (pid == 0)	// child process
	{
		// something about trying paths
		// but for testing now willuse execvp instead

		if (execvp(cmd->words[0], cmd->words) == -1)
		{
			perror("Error in execvp");	// could definitely have a better message
		}
		exit(1);	// is 1 the right number?

	}
	else if (pid < 0) 	// error
	{
		perror("Error");
		return (1);
	}
	else	// parent process
	{
		// apparently you can put this in a loop where it checks status and acts
			// accordingly... but idk, also there are options
			// doesn't have to be NULL... 
	//	wpid = waitpid(pid, &status, NULL);
		// seeing as i don't know how to use the args and options i'll just do it simple
		wpid = waitpid(pid, NULL, 0);

	}
	return (0);
}

	// not convinced this func is that useful, could put all this elsewhere
int execute_cmd(t_cmd *cmd)
{
	int	ret;

	if (!cmd || !cmd->words || !cmd->words[0])
		return (1); // i think 1 is cor return
	// dif between builtins here?
	ret = builtin_triage(cmd);
	if (ret != -2)
		return (ret);	// no idea if this is any good...

	// now executing reg external command
	if (execute_external(cmd) != 0)
	{
		// free? msg?
		return (1);
	}
    return (0);
}



	// better name?
	// cuz what we're doing is sending the t_cmds to another func that will execute
int	input_line_exec_loop(t_input_line *input)
{
    int     ret;
	t_cmd	*tmp;

	// something about cycleing through the linked list
	if (!input)
		return (1);
	// something about pipes prolly?
	tmp = input->cmds;
	while (tmp)
	{
		ret = execute_cmd(tmp);
		if (ret != 0)
        {
			// free something?
            return (ret);
        }
		// super simple for now
		tmp = tmp->next;
	}

	// first check builtins
	// then run as a normal func
	return (0);
}
