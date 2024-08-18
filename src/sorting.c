/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/18 12:32:36 by dulrich          ###   ########.fr       */
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

int	choose_insertion(t_link **stack, t_link *link)
{
	t_link	*biggest;
	t_link	*closest;
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
	while (*stack != closest)
		rb(stack);
	return (is_bigger);
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

void	push_cheapest(t_link **a, t_link **b, t_link *first, t_link *second)
{
	int	push_first;

	push_first = compare_moves(first, second);
	if (push_first)
	{
		while (*a != first)
			ra(a);
		choose_insertion(b, first);
	}
	else
	{
		while (*a != second)
			rra(a);
		choose_insertion(b, second);
	}
/* 	print_stack(*a, "a before pushing");
	print_stack(*b, "b before pushing"); */
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
