/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:24:55 by me                #+#    #+#             */
/*   Updated: 2022/01/26 15:24:28 by me               ###   ########.fr       */
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
	WORD,	// a-Z and _
	PIPE,	// | // might not be necessary?
	RIN,	// < // as in Redirection In
	ROUT,	// >
	HDOC,	// <<
	AROUT	// >>
	// we need more, need to differenciate between < and < with words after.
}				t_e_type;	// i know the _e_ isn't necessary but i don't care

typedef struct	s_tok
{

	t_e_type	type;
	// rather than making a copy of the string we could have a pointer and a len?
	char		*str;	// should this be the exapanded string or OG
						// like do i perform alterations to it and use it at the end?

	// should it be a linked list?
	struct s_tok	*next;

}				t_tok;

typedef struct	s_cmd
{
	t_tok				*tokens;
	char				**words;	// might change namelater
	// do i modify words or str in tokens list?

	// acutally useless
	int					dqs;	// double quotes
	int					sqs;
	
	int					redirects;	// no idea what this shit will be... an int?
	int					pipe[2];	//  do we want this?	// is it the position?

	int					exit_status;	// for $? exit status expansion

	struct s_input_line	*home_inp;
	struct s_cmd		*next;
}				t_cmd;

typedef struct	s_input_line
{
	// this value starts at 1...
	int					num;		// or we use an ilist and a pointer to this struct?
	char				*line;	// as in the full line read with gnl
	// we could have a linked list of the broken up lines?
	// we could also have a string that's the final product we are to send to execve?
	
	struct s_cmd		*cmds;
	struct s_sh			*home_sh;
	
	struct s_input_line	*next;
}				t_input_line;


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

	t_input_line	*inputs;	// would also serve for the history?

	// would it be intersting to copy paste the entire struct, line and tokens
		// when someone uses the historique to grab an old command?
		// or would that not work cuz they can modify the line?
		// this would only work if you can't edit lines from the historique...
		// which only works if BOTH you can't arrow key through a line
		// and in the specific case of the historique you can't backspace.
}				t_sh;

/*
**	Main
*/

int				create_input_line_elem(t_sh *all, char *line);
int				minishell(t_sh *all, int i);

/*
**	Init
*/

int				ft_get_all_env(t_sh *all);
int				init_sh(t_sh *all);

/*
**	Printing
*/

void			ft_prompt(void);
void			ft_simple_print();

/*
**	Lexer
*/

int				lexer(t_input_line *input);

/*
**	Handle Quotes
*/

int	strtab_len(char **tab);

char			**dup_longer_strtab(char **tab, int add);
//int	dup_longer_strtab(char ***tab, int add);

char			**concat_strtabs(char **t1, char **t2);
//int	wordify_quotes(char *line, char **words);
char			**wordify_quotes(char *line, char **words);

/*
**	Make Tokens
*/

/*
**	Parser
*/

int				parser(t_input_line *input);

/*
**	Expansions
*/

int				perform_expansions(t_cmd *cmd);

/*
**	Redirections
*/

/*
**	Pipes
*/

/*
**	Execution
*/

int execute_external(t_cmd *cmd);
int execute_cmd(t_cmd *cmd);
int	input_line_exec_loop(t_input_line *input);

/*
**	Parser
*/

/*
**	Token List
*/

t_tok			*toknew(t_e_type type, char *str);
int				tokadd_front(t_tok **lst, t_tok *new);
int				tokdel_all(t_tok **lst);

/*
**	Command List
*/

t_cmd			*cmd_new(t_input_line *input, char **words);
int				cmd_add_front(t_cmd **lst, t_cmd *new);
int				cmd_add_back(t_cmd **lst, t_cmd *new);
int				cmd_del_all(t_cmd **lst);
int				print_all_cmd_strs(t_cmd *cmds);

/*
**	Input Line List
*/

t_input_line	*input_line_new(t_sh *all, char *line, int num);
int				input_line_add_front(t_input_line **lst, t_input_line *new);
int				input_line_del_all(t_input_line **lst);

/*
**	Builtins Hub
*/

int				builtin_triage(t_cmd *cmd);

/*
**	Builtin CD
*/

/*
**	Builtin PWD
*/

/*
**	Builtin ENV
*/

int				builtin_env(t_sh *all);

/*
**	Builtin
*/

/*
**	Execute something needs a better name
*/

int				input_line_exec_loop(t_input_line *input);

/*
**	Free
*/

int				free_sh(t_sh *all);

/*
**	Split_Until
*/

char			**split_until(char *s, char *set, int l);

/*
**	Make Tokens (might be tmp)
*/

int				str_contains_only(char *str, char *set);
int				add_token(t_cmd *cmd, char **words);

/*
**	Unused
*/

int				add_back_strtab(char **tab, char *str);



#endif
