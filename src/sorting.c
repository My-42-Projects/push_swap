/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/11 15:38:15 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Make it more efficient by finding out which way to rotate
void	choose_insertion(t_link **stack, t_link *link)
{
	t_link	*biggest;
	t_link	*closest;
	// int		reverse;

	if (stack == NULL || (*stack) == NULL)
		return ;
	/* reverse = FALSE;
	if (ft_strncmp(determine_rotation(stack, link), "rr", 2) == 0)
		reverse = TRUE; */
	biggest = get_biggest_link(*stack);
	if (link->index > biggest->index)
		closest = get_closest_link(stack, link, 1);
	else
		closest = get_closest_link(stack, link, 0);
	while (*stack != closest)
		rb(stack);
}

//Rotate or rev rot **a until the link to push is at the top,
//then find where to insert it into **b
//lastly, rotate **b to the correct spot and then push
void	push_cheapest(t_link **a, t_link **b, t_link *first, t_link *second)
{
	int		push_first;

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
	int		i;

	i = 0;
	cheapest_link1 = NULL;
	cheapest_link2 = NULL;
	current = get_first_link(*a);
	while (current)
	{
		print_stack(*a, "a");
		if (current->chunk == chunk)
		{
			cheapest_link1 = calc_moves_to_push(a, current, TRUE);
		}
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
		printf("Current->nbr: %d\n", current->nbr);
		printf("Rounds gone: %d\n", ++i);
	}
	push_cheapest(a, b, cheapest_link1, cheapest_link2);
	print_stack(*a, "a after pb");
	print_stack(*b, "b after pb");
}
