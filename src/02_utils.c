/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:12:28 by gfantoni          #+#    #+#             */
/*   Updated: 2024/06/13 15:21:14 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sig_handler(int signum) 
{
	t_mini	*mini;
	
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		rl_redisplay();
		mini = get_mini_address();
		mini->status = 130;
	}
}

void    sig_handler_heredoc(int signum)
{
	t_mini	*mini;
	
    if (signum == SIGINT)
    {
        write(STDIN_FILENO, "\n", 1);
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
		mini = get_mini_address();
		mini->status = 130;
    }
}