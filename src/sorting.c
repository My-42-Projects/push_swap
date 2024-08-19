/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/19 19:30:32 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* int	choose_insertion(t_link **stack, t_link *link)
{
	t_link	*biggest;
	t_link	*closest;
	int		norm_rot;
	int		is_bigger;

	if (stack == NULL || (*stack) == NULL)
		return (1);
	is_bigger = FALSE;
	biggest = get_biggest_link(*stack);
	if (link->index > biggest->index)
	{
		closest = get_closest_link(stack, link, 1);
		is_bigger = TRUE;
	}
	else
		closest = get_closest_link(stack, link, 0);
	norm_rot = determine_rotation(stack, closest);
	if (norm_rot)
	{
		while (*stack != closest)
			rb(stack);
	}
	else
	{
		while (*stack != closest)
			rrb(stack);
	}
	return (is_bigger);
} */

//Works!!!

t_link	*choose_insertion(t_link **stack, t_link *link)
{
	t_link	*biggest;
	t_link	*closest;

	if (stack == NULL || (*stack) == NULL)
		return (NULL);
	biggest = get_biggest_link(*stack);
	if (link->index > biggest->index)
		closest = get_closest_link(stack, link, 1);
	else
		closest = get_closest_link(stack, link, 0);
	return (closest);
}

/* void	push_cheapest(t_link **a, t_link **b, t_link *first, t_link *second)
{
	int	push_first;
	int	is_bigger;

	is_bigger = FALSE;
	push_first = compare_moves(first, second);
	if (push_first)
	{
		while (*a != first)
			ra(a);
		if (choose_insertion(b, first) == 1)
			is_bigger = TRUE;
	}
	else
	{
		while (*a != second)
			rra(a);
		if (choose_insertion(b, second) == 1)
			is_bigger = TRUE;
	}
	pb(a, b);
	if (is_bigger)
		printf("is_bigger\n");
	if ((*b)->next && (*b)->index < (*b)->next->index)
		sb(b);
} */

//add an option to rr or rrr if applicable to save on moves
/* void	push_cheapest(t_link **a, t_link **b, t_link *first, t_link *second)
{
	t_link	*closest;
	t_link	*current;
	int		push_first;
	int		times;

	push_first = compare_moves(first, second);
	if (push_first)
	{
		closest = choose_insertion(b, first);
		times = calc_rot_both(a, b, first, closest);
		rr(a, b, times);
		current = *a;
		while (current != first)
		{
			ra(a);
			current = *a;
		}
		current = *b;
		while (current != closest)
		{
			rb(b);
			current = *b;
		}
	}
	else
	{
		closest = choose_insertion(b, second);
		times = calc_rot_both(a, b, second, closest);
		rrr(a, b, times);
		current = *a;
		while (current != first)
		{
			rra(a);
			current = *a;
		}
		current = *b;
		while (current != closest)
		{
			rrb(b);
			current = *b;
		}
	}
	pb(a, b);
	if ((*b)->next && (*b)->index < (*b)->next->index)
		sb(b);
} */

void	push_cheapest(t_link **a, t_link **b, t_link *first, t_link *second)
{
	t_link	*closest;
	t_link	*current;
	int		times;

	(void)second;
	closest = choose_insertion(b, first);
	times = calc_rot_both(a, b, first, closest);
	rr(a, b, times);
	current = *a;
	while (current != first)
	{
		ra(a);
		current = *a;
	}
	current = *b;
	while (current != closest)
	{
		rb(b);
		current = *b;
	}
	pb(a, b);
	if ((*b)->next && (*b)->index < (*b)->next->index)
		sb(b);
}

//Find the cheapest link to push from **a to **b
void	get_cheapest_link(t_link **a, t_link **b, int chunk)
{
	t_link	*cheapest_link1;
	t_link	*cheapest_link2;
	t_link	*current;

	cheapest_link1 = NULL;
	cheapest_link2 = NULL;
	current = get_first_link(*a);
	while (current)
	{
		if (current->chunk == chunk)
			cheapest_link1 = calc_moves_to_push(a, current, TRUE);
		if (cheapest_link1 != NULL)
		{
			current = get_last_link(*a);
			while (current)
			{
				if (current->chunk == chunk)
				{
					cheapest_link2 = calc_moves_to_push(a, current, FALSE);
					break ;
				}
				current = current->prev;
			}
			break ;
		}
		current = current->next;
	}
	push_cheapest(a, b, cheapest_link1, cheapest_link2);
}
