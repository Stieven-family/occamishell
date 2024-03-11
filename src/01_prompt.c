/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:10:34 by gfantoni          #+#    #+#             */
/*   Updated: 2024/03/11 18:18:52 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/pipex.h"

void	mini_prompt(t_pipex *mini)
{
	mini_ctrl_signal();
	mini->cmd_line = NULL;
	while (1)
	{
		mini->cmd_line = readline("prompt > ");
		mini_parse_readline(mini);
		if (mini->cmd_line == NULL)
		{
			printf("exit\n");
			mini_safe_exit(mini);
		}
		mini_execute(mini);
		waitpid(mini->pid1, NULL, 0);
		mini_free_split(mini->split_cmd_line);
		free(mini->cmd_line);
	}
}