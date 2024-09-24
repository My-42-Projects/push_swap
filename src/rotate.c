/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:56:25 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:52:58 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_link **stack)
{
	t_link	*last;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = get_last_link(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_link **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_link **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_link **a, t_link **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rotate_both(t_link **a, t_link **b, t_link *link, bool reverse)
{
	if (reverse)
	{
		while (*a != link->target && *b != link)
			rrr(a, b);
	}
	else
	{
		while (*a != link->target && *b != link)
			rr(a, b);
	}
	find_pos(*a);
	find_pos(*b);
}
