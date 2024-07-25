/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:46 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/25 13:14:07 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_link **a, t_link **b)
{
	int	stack_len;

	stack_len = stack_len(a);
	if (stack_len <= 3)
		sort_three(a);
	else if (stack_len <= 5)
		sort_five(a, b);
	else
		sort_all(a, b, stack_len);
}

void	sort_all(t_link **a, t_link **b, int amount)
{
	int	chunk;
	int	max_chunk;

	if (amount <= 100)
		max_chunk = 5;
	else
		max_chunk = 11;
	chunk = 0;
	while (stack_len(a))
	{
		sort_b(b);
		get_cheapest_link(a, b, chunk);
		if (chunk != max_chunk)
		{
			if (chunk_is_done(a, chunk))
				chunk++;
		}
	}
	if (!is_sorted(b, TRUE))
		last_rotation(b); //implement this
	while (stack_len(b)) //implement this
		pa(a, b);
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
