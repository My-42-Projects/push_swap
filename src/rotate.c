/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:56:25 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/18 22:29:16 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

extern int	counter;

void	rotate(t_link **stack, int reverse)
{
	int		len;
	t_link	*last_link;
	
	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last_link = get_last_link(*stack);
	if (reverse)
	{
		last_link->prev->next = NULL;
		last_link->next = *stack;
		last_link->prev = NULL;
		*stack = last_link;
		last_link->next->prev = last_link;
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

void	rb(t_link **b)
{
	rotate(b, FALSE);
	write(1, "rb\n", 3);
}

void	rr(t_link **a, t_link **b, int times)
{
	while (times > 0)
	{
		rotate(a, FALSE);
		rotate(b, FALSE);
		write(1, "rr\n", 3);
		times--;
		counter++;
	}
}
