/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:46 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/20 20:35:32 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	counter = 0;

void	push_swap(t_link **a, t_link **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else if (len <= 5)
		sort_five(a, b);
	else
		sort_all(a, b, len);
/* 	print_stack(*a, "a after sorting");
	printf("%d\n", counter); */
	free_links(a);
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
	while (*a)
	{
		get_cheapest_link(a, b, chunk);
		if (chunk < max_chunk)
		{
			if (chunk_is_done(a, chunk))
				chunk++;
		}
	}
	if (!is_sorted(*b, TRUE))
		last_rotation(b);
	while (*b)
		pa(a, b);
}

void	sort_five(t_link **a, t_link **b)
{
	t_link	*current;
	t_link	*smallest;
	int		index;

	smallest = get_smallest_link(*a);
	while (*a != smallest)
		ra(a);
	pb (a, b);
	if (stack_len(*a) > 3)
	{
		smallest = get_smallest_link(*a);
		while (*a != smallest)
			ra(a);
		pb (a, b);
	}
	sort_three(a);
	if ((stack_len(*b) > 1) && ((*b)->nbr < (*b)->next->nbr))
		sb(b);
	while (*b)
	{
		current = *a;
		index = (*b)->index;
		if (current->index == index + 1)
			pa(a, b);
		else
			ra(a);
	}
	smallest = get_smallest_link(*a);
	while (*a != smallest)
		ra(a);
}

void	sort_three(t_link **stack)
{
	t_link	*biggest;

	biggest = get_biggest_link(*stack);
	if ((*stack) == biggest)
		ra(stack);
	else if ((*stack)->next == biggest)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}
