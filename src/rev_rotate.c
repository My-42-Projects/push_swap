/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:17:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:52:53 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate(t_link **stack)
{
	t_link	*head;
	t_link	*last;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = get_last_link(*stack);
	head = *stack;
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
}

void	rra(t_link **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_link **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_link **a, t_link **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
