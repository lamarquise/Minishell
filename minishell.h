/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:24:55 by me                #+#    #+#             */
/*   Updated: 2022/01/21 07:47:23 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
// some more prolly
#include "minilib.h"

// some defines

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

// i'm guessing i'll need something like this...
	// swap names with below?
	// no idea what the values should be yet but whatever
	// is it ok for me to do the typedef here?
typedef enum	e_type
{			// NO see vportens' struct.h for some good structs
	WORD,
	PIPE,	// might not be necessary?
	RIN,	// as in Redirection In
	ROUT,
	HDOC,
	AROUT
	// we need more, need to differenciate between < and < with words after.
}				t_e_type;	// i know the _e_ isn't necessary but i don't care

typedef struct	s_tok
{

	t_e_type	type;
	char		*str;	// should this be the exapanded string or OG
						// like do i perform alterations to it and use it at the end?

	// should it be a linked list?
	struct s_tok	*next;

}				t_tok;

typedef struct	s_cmd_line
{
	// this value starts at 1...
	int					num;		// or we use an ilist and a pointer to this struct?
	t_tok				*tokens;
	char				*line;	// as in the full line read with gnl
	// we could have a linked list of the broken up lines?
	// we could also have a string that's the final product we are to send to execve?
	
	int					dqs;	// double quotes
	int					sqs;
	int					pipe;	//  do we want this?	// is it the position?
	struct s_sh			*home;
	
	struct s_cmd_line	*next;
}				t_cmd_line;


typedef struct	s_sh	// this is our main struct, we will call it all
{
	// a linked list of env vars?
		// we could do something more complicated with key,value pairs in a linkedlist
	// might be worth keeping a copy of all the og stuff in here?
	int		ac;
	char	**av;
	char	**envir;	// this is what the main passes us, just in case we need it again?
	// would it be helpful to keep
	//int	status; // in here too?

	
	int		n_hist;	// the number of commands entered so far, just a counter
	t_list	*env;

	t_cmd_line	*lines;	// would also serve for the history?

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

int			create_cmd_line_elem(t_sh *all, char *line);
int			minishell(t_sh *all, int i);

/*
**	Init
*/

int			ft_get_all_env(t_sh *all);
int			init_sh(t_sh *all);

/*
**	Printing
*/

void		ft_prompt(void);
void		ft_simple_print();

/*
**	Lexer
*/

int			lexer(t_cmd_line *cmd);

/*
**	Parser
*/

/*
**	Token List
*/

t_tok		*ft_toknew(t_e_type type, char *str);
int			ft_tokadd_front(t_tok **lst, t_tok *new);
int			ft_tokdel_all(t_tok **lst);

/*
**	Command List
*/

t_cmd_line	*ft_cmdline_new(t_sh *all, char *line, int num);
int			ft_cmdline_add_front(t_cmd_line **lst, t_cmd_line *new);
int			ft_cmdline_del_all(t_cmd_line **lst);

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
**	Builtin ENV
*/

int			builtin_env(t_sh *all);

/*
**	Builtin
*/

/*
**	Free
*/

int			free_sh(t_sh *all);

/*
**	Split_Until
*/

char		**split_until(char const *s, char *set, int l);


#endif
