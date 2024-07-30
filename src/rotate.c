/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:56:25 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/30 21:22:02 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_link **stack, int reverse)
{
	int		len;
	t_link	*last_link;
	
	len = stack_len(stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last_link = get_last_link(*stack);
	if (reverse)
	{
		(*stack)->prev = last_link;
		(*stack)->prev->prev = NULL;
		last_link = last_link->prev;
		last_link->prev->next = NULL;
	}
	else
	{
		last_link->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last_link->next->prev = last_link;
		last_link->next->next = NULL;
	}
}

void	ra(t_link **a)
{
	rotate(a, FALSE);
	write(1, "ra\n", 3);
}

void	rra(t_link **a)
{
	rotate(a, TRUE);
	write(1, "rra\n", 4);
}

void	rb(t_link **b)
{
	rotate(b, FALSE);
	write(1, "rb\n", 3);
}

void	rrb(t_link **b)
{
	rotate(b, TRUE);
	write(1, "rrb\n", 4);
}
