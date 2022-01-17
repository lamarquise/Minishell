/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:24:55 by me                #+#    #+#             */
/*   Updated: 2022/01/17 23:57:57 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
// some more prolly
#include "minilib.h"

// some defines

// i'm guessing i'll need something like this...
	// swap names with below?
	// no idea what the values should be yet but whatever
	// is it ok for me to do the typedef here?
typedef enum	e_type
{			// NO see vportens' struct.h for some good structs
	WORD,
	PIPE,
	RIN,	// as in Redirection In
	ROUT,
	HDOC,
	AROUT
}				t_e_type;	// i know the _e_ isn't necessary but i don't care

/*

	word
	pipe
	<
	>
	>>
	<<
	


	A-Z words?
		_ is also a valid char for words!
	' Quote
	" Double Quote
	| Pipe
	' ' whitespace
		\t \n also whitespaces?
	> Greater
	< Lesser
	$ Dollar? call something else?
	\ Backslash 	// wait, maybe i'm not supposed to handle this...
	- Dash
		is it techinally part of a word? like ls -la, -la is an arg, i assume i would
		send the whole thing?
	0 NULL ? call something else? dif symbol?

*/

typedef struct	s_tok
{

	t_e_type	type;


	// should it be a linked list?
	struct s_tolk	*next;

}				t_tok;

typedef struct	s_cmd_line
{
	int		num;		// or we use an ilist and a pointer to this struct?
	t_tok	*tokens;
	char	*line;
}				t_cmd_line;


typedef struct	s_sh	// this is our main struct, we will call it all
{
	// no idea what to put in it...
	// a linked list of env vars?
		// we could do something more complicated with key,value pairs in a linkedlist

	t_list	*env;

//	t_tok	*tokens;
	t_cmd_line	*lines;	// would also serve for the history?
	// maybe it would be better to use t_lists?

	// would it be intersting to copy paste the entire struct, line and tokens
		// when someone uses the historique to grab an old command?
		// or would that not work cuz they can modify the line?
		// this would only work if you can't edit lines from the historique...
		// which only works if BOTH you can't arrow key through a line
		// and in the specific case of the historique you can't backspace.

	// something about commands and how they pipe together?


	// i'm assuming somewhere in here will be the historique?
	// but i also think a lot of stuff will just be pointers so
	// after each new line i can free it all and get back to a clean minishell struct
}				t_sh;

/*
**	Main
*/


int			minishell(t_sh *all, int i);

/*
**	Printing
*/

void		ft_prompt(void);
void		ft_simple_print();

/*
**	Lexer
*/

int			lexer(t_sh *all, char *line);

/*
**	Parser
*/

/*
**	Builtins Hub
*/

/*
**	Builtin CD
*/

/*
**	Builtin PWD
*/

/*
**	Builtin
*/

/*
**	Free
*/


#endif
