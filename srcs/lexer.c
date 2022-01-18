/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:50:26 by me                #+#    #+#             */
/*   Updated: 2022/01/18 20:25:02 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// the work of the Lexer is to identify tokens

// how will it work?
/*
	ok so first we need to group things by quotes?
	let's start by assuming no quotes

	we split everythign around space \t and \n
		do we even really need \n?
	then we determin what each split thing is and add it to a linked list
		of tokens
*/

// int?
int	lexer(t_sh *all, char *line)
{
	// what is meant to be done here? idk cuz i don't know the diff between a
	// parser and a lexer...
	(void)all;
	(void)line;



	return (0); // means all good
	// return (2); if parsing error!
	// return (-1); if need to exit out of minishell program
}








