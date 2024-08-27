/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:46 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/27 15:15:43 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_link **a, t_link **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else
	{
		pb(a, b);
		pb(a, b);
		sort_all(a, b);
	}
	/* print_stack(*a, "a after sorting");
	print_stack(*b, "b after sorting"); */
	free_links(a);
}

void	push_back(t_link **a, t_link **b)
{
	t_link	*target;
	t_link	*current;
	t_link	*to_push;
	t_link	*biggest;
	int		reverse;

	current = *a;
	to_push = *b;
	biggest = get_biggest_link(*a);
	if (to_push->index > biggest->index)
		target = biggest;
	else
		target = get_closest_link(a, to_push, FALSE);
	reverse = determine_rotation(a, target);
/* 	print_stack(*b, "b before pushing");
	print_stack(*a, "a before pushing");
	printf("To push: %d\n", to_push->index);
	printf("Target: %d\n", target->index); */
	while (current != target)
	{
		if (reverse)
			rra(a);
		else
			ra(a);
		current = *a;
	}
	// if (target->index > to_push->index && reverse)
	if (to_push->index > target->index)
		ra(a);
	pa(a, b);
}

void	sort_all(t_link **a, t_link **b)
{
	while (stack_len(*a) > 3)
		get_cheapest_link(a, b);
	sort_three(a);
	while (*b)
		push_back(a, b);
	if (!is_sorted(a, FALSE))
		last_rotation(a, TRUE);
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
