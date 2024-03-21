/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/03/21 11:52:12 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/includes/libft.h"
# include "../include/pipex.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef struct s_cmd_line_list
{
	void					*content;
	int						is_valid;
	struct s_cmd_line_list	*next;
}			t_cmd_line_list;

// 00_main.c
int			main(int argc, char *argv[], char *envp[]);

// 01_prompt.c
void		mini_prompt(t_pipex *mini);

// 01_utils.c
//t_analysis	*init_analysis(t_list **list_memory);
void		mini_init(t_pipex *pipex);
void		mini_trashman_collector(t_list **list_memory, void *trash);
void		mini_safe_exit(t_pipex *mini);

// 02_ctrl_signal.c
void	mini_ctrl_signal(void);
void	sig_handler(int signum);

// 03_launch_executable.c
void	mini_execute(t_pipex *mini);

// 04_special_parameter.c
void	mini_special_parameter(t_pipex *mini);
char	*mini_expand(char c, t_pipex *mini);
int		ft_get_exit_status(int exit_status);

// 05_analysis.c
void	mini_analysis(t_pipex *mini);
void	automaton(char *str, t_token **token_list, int start, int state);
int		get_next_state(int state, int column);
int	get_column(char c);
int	is_end_state(int num);
int	is_back_state(int num);
int	is_error_state(int num);

// t_cmd_line_list *mini_fill_analysis_list(char **split_cmd_line);
// void	mini_get_in_and_output(t_cmd_line_list **analysis_list, t_analysis *analysis);
// int		search_redirect(char *analysis_str);
// void	handle_redirect(t_analysis *analysis, char *analysis_str, int redirect_type);

// 05_utils.c
void	mini_lstdelone(t_token *lst);
t_token	*mini_lstnew(void *token);
void	mini_lstadd_back(t_token **lst, t_token *new);
t_token	*mini_lstlast(t_token *lst);
void	debug_print_split(char **str); // FOR DEBUG ONLY
void	debug_print_list(t_token **head); // FOR DEBUG ONLY


// void			mini_lstdelone(t_cmd_line_list *lst);
// t_cmd_line_list	*mini_lstnew(void *content);
// void			mini_lstadd_back(t_cmd_line_list **lst, t_cmd_line_list *new);
// t_cmd_line_list	*mini_lstlast(t_cmd_line_list *lst);
// void			debug_print_split(char **analysis_list); // FOR DEBUG ONLY
// void			debug_print_list(t_cmd_line_list **head); // FOR DEBUG ONLY


#endif