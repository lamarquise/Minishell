/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <erlazo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:26:33 by erlazo            #+#    #+#             */
/*   Updated: 2022/01/25 18:28:14 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// called by parser aka post processing of **words to turn redirection of words
	// to turn > < >> << in correct behavior


// I have no idea how redirections work
	// no idea if we only have to set that up for when cmd is a builtin cuz other cmds handle that shit
	// themselves, ikd will find out

