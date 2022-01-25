/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <erlazo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:28:22 by erlazo            #+#    #+#             */
/*   Updated: 2022/01/25 18:30:02 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// called by parser aka post processing of **words and cmds to connect cmd inputs and outputs

// should it be called by parser? should it instead be called after parser ? cuz operates on full
	// cmd linked list not just **words of 1 cmd... not sure
