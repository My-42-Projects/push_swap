/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:00:14 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/25 21:27:20 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	chunk_is_done(t_link **head, int chunk)
{
	while (*head)
	{
		if ((*head)->chunk == chunk)
			return (0);
		*head = (*head)->next;
	}
	return (1);
}

t_link	*find_biggest_link(t_link **stack)
{
	t_link	*biggest;

	biggest = *stack;
	while (*stack)
	{
		if ((*stack)->nbr > biggest->nbr)
			biggest = *stack;
		*stack = (*stack)->next;
	}
	return (biggest);
}

char	*determine_rotation(t_link **stack, t_link *link)
{
	int	rot;
	int	mid;

	mid = stack_len(stack) / 2;
	rot = 0;
	while (*stack)
	{
		if (*stack == link)
			break ;
		rot++;
	}
	if (rot <= mid)
		return ("rr");
	else
		return ("rrr");
}

void	last_rotation(t_link **stack)
{
	t_link	*biggest;
	char	*rotation;

	biggest = find_biggest_link(stack);
	rotation = determine_rotation(stack, biggest);
	while (!is_sorted(stack, TRUE))
	{
		if (rotation == "rr")
			rb(b);
		else
			rrb(b);
	}
}
