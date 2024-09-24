/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:58:53 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:53:10 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_link **stack)
{
	t_link	*tmp;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_link **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_link **b)
{
	swap(b);
	write(1, "sb\n", 3);
}
