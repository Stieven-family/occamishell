/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:29:13 by gfantoni          #+#    #+#             */
/*   Updated: 2024/04/01 16:30:39 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	mini_parser(t_mini *mini)
{
	int		nbr_cmds;

	nbr_cmds = 0;
	if (mini->token_list)
	{
		nbr_cmds = mini_count_nbr_pipes(mini->token_list) + 1;
		mini->commands = (t_token **)malloc(sizeof(t_token *) * nbr_cmds + 1);
		collect_mem(mini->commands);
		mini_fill_cmd_array(mini);
		//debug_print_array_list(mini); // FOR DEBUG ONLY
	}
}

int	mini_count_nbr_pipes(t_token *token_list)
{
	t_token *temp;
	int		nbr_pipes;

	temp = token_list;
	nbr_pipes = 0;
	while (temp)
	{
		// if (temp->token[0] == '|')
		if (!ft_strncmp(temp->token, "|", 2))
			nbr_pipes++;
		temp = temp->next;
	}
	return (nbr_pipes);
}

void	mini_fill_cmd_array(t_mini  *mini)
{
	t_token	*current;
	t_token *new;
	char	*token;
	int		i;

	new = NULL;
	i = 0;
	current = mini->token_list;
	while (current)
	{
		token = current->token;
		if (!ft_strncmp(token, "|", 2))
		{
			mini->commands[i] = new;
			new = NULL;
			i++;
		}
		else
			mini_token_lstadd_back(&new, mini_t_token_dup(current));
		current = current->next;
	}
	mini->commands[i] = new;
}

t_token	*mini_t_token_dup(t_token *t)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token));
	if (new_node == NULL)
		return (NULL);
	new_node->token = t->token;
	new_node->gender = t->gender;
	new_node->specie = t->specie;
	new_node->next = NULL;
	new_node->prev = NULL;
	collect_mem(new_node);
	return (new_node);
}