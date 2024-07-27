/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:12:39 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/27 21:18:51 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(t_link **stack, int nbr)
{
	if (stack == NULL || *stack == NULL)
		return (0);
	while (*stack)
	{
		if ((*stack)->nbr == nbr)
			return (1);
		*stack = (*stack)->next;
	}
	return (0);
}

int	is_sorted(t_link *stack, int reverse)
{
	if (reverse)
	{
		stack = get_last_link(&stack);
		while (stack->prev)
		{
			if (stack->nbr < stack->next->nbr)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	else
		while (stack)
		{
			if (stack->nbr > stack->next->nbr)
				return (0);
			stack = stack->next;
		}
		return (1);
}
