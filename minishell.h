/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:24:55 by me                #+#    #+#             */
/*   Updated: 2022/01/14 17:45:52 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
// some more prolly
#include "minilib.h"

// some defines

// celia called this cmd, not sure which i like more
typedef struct	s_tolk
{
	// char or int?
//	char	*val;
	int		val;
	// something type;
	int		status;
	int		pipe;	// not sure which if these i will end up using...

	// pid_t	pid; 	// a pid?

	// should it be a linked list?
	struct s_tolk	*next;

}				t_tolk;

typedef struct	s_sh	// this is our main struct, we will call it all
{
	// no idea what to put in it...
	// a linked list of env vars?

	t_list		*env;


}				t_sh

/*
**	Printing
*/

void		ft_prompt(void);
void		ft_simple_print();


#endif
