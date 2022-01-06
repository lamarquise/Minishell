/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:24:55 by me                #+#    #+#             */
/*   Updated: 2022/01/06 00:57:00 by me               ###   ########.fr       */
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


/*
**	Printing
*/

void		ft_prompt(void);
void		ft_simple_print();


#endif
