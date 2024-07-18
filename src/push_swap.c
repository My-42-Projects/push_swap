/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:46 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/18 09:59:31 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_link **a, t_link **b)
{
	if (stack_len(a) <= 3)
		sort_three(a);
	else if (stack_len(a) <= 5)
		sort_five(a, b);
	else if (stack_len(a) <= 100)
		sort_all(a, b, 100);
	else
		sort_all(a, b, 500);
}

void	sort_all(t_link **a, t_link **b, int amount)
{
	int	chunk;
	int	max_chunk;
	int	stack_len_a;

	if (amount == 100)
		max_chunk = 5;
	else
		max_chunk = 11;
	chunk = 1;
	stack_len_a = stack_len(a);
	while (stack_len_a && chunk <= max_chunk)
	{
		sort_b(b);
		get_cheapest_link(a, b, chunk);
		if (chunk_is_done(a, chunk))
			chunk++;
		stack_len_a--;
	}
}

void	sort_five(t_link *a, t_link *b)
{
	pb(a);
	if (stack_len(a) == 5)
		pb(a);
	sort_three(a);
	if (b->nbr > b->next->nbr)
			sb(b);
	while (b)
	{
		while (b->nbr > a->nbr && b->nbr < a->next->nbr)
			ra(a);
		pa(b);
		b = b->next;
	}
}

void	sort_three(t_link *stack)
{
	if (stack_len(stack) == 2)
		sa();
	else if ((stack->nbr > stack->next->nbr) && 
	(stack->nbr > stack->next->next->nbr))
	{
		ra();
		if (stack->next->nbr > stack->next->next->nbr)
			sa();
	}
	else if ((stack->next->nbr > stack->nbr) && 
	(stack->next->nbr > stack->nbr))
	{
		rra();
		if (stack->next->next->nbr > stack->nbr)
			sa();
	}
	else if ((stack->next->next->nbr > stack->nbr) &&
			(stack->next->next->nbr > stack->next->nbr))
	{
		if (stack->nbr > stack->next->nbr)
			sa();
	}
}
