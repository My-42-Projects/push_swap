/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:00:14 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:52:33 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	last_rotation(t_link **stack)
{
	t_link	*smallest;
	t_link	*current;

	smallest = get_smallest_link(*stack);
	current = *stack;
	while (current != smallest)
	{
		if (smallest->above_mid)
			ra(stack);
		else
			rra(stack);
		current = *stack;
	}
}

void	allocate_index(t_link **stack, int	*nbrs)
{
	int		i;
	int		len;
	t_link	*head;

	i = 0;
	len = stack_len(*stack);
	head = get_first_link(*stack);
	if (*stack == NULL)
		*stack = head;
	while (i < len)
	{
		if ((*stack)->next == NULL)
			*stack = head;
		else
			*stack = (*stack)->next;
		if (nbrs[i] == (*stack)->nbr)
		{
			i++;
			(*stack)->index = i;
		}
	}
}

void	find_pos(t_link *stack)
{
	int	i;
	int	mid;

	if (stack == NULL)
		return ;
	i = 0;
	mid = stack_len(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= mid)
			stack->above_mid = true;
		else
			stack->above_mid = false;
		stack = stack->next;
		i++;
	}
}
