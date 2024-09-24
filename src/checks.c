/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:12:39 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:52:03 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && \
		!(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(t_link *stack, int nbr)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->nbr == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_sorted(t_link **stack, int reverse)
{
	t_link	*current;

	current = *stack;
	if (reverse)
	{
		current = get_last_link(current);
		while (current->prev)
		{
			if (current->nbr > current->prev->nbr)
				return (0);
			current = current->prev;
		}
		return (1);
	}
	else
	{
		while (current->next)
		{
			if (current->nbr > current->next->nbr)
				return (0);
			current = current->next;
		}
		return (1);
	}
}
