/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/18 10:12:55 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_insert(t_link **stack, int index)
{
	t_link	*right_spot;

	if (!(*stack) || !(*stack)->next)
		return ;
	right_spot = find_right_spot(stack, index, 0);
	if (!right_spot)
		return ;
	while (*stack != right_spot)
		rb();
}

void	push_cheapest(t_link **a, t_link **b, t_link *first_node, t_link *second_node)
{
	int	push_first;

	push_first = compare_moves(first_node, second_node);
	if (push_first)
	{
		while (first_node != *a)
			ra();
		choose_insert(b, first_node->index);
	}
	else
	{
		while (second_node != *a)
			rra();
		choose_insert(b, second_node->index);
	}
	pb(a, b);
}

void	get_cheapest_link(t_link **a, t_link **b, int chunk)
{
	t_link	*cheapest_link1;
	t_link	*cheapest_link2;

	cheapest_link1 = NULL;
	cheapest_link2 = NULL;
	while (*a)
	{
		if ((*a)->chunk == chunk)
			cheapest_link1 = calc_moves_to_push(a, *a, 1);
		if (cheapest_link1)
		{
			find_last_link(a);
			while (*a != cheapest_link1)
			{
				if ((*a)->chunk == chunk)
				{
					cheapest_link2 = calc_moves_to_push(a, *a, 0);
					break ;
				}
				*a = (*a)->prev;
			}
		}
		*a = (*a)->next;
	}
	push_cheapest(a, b, cheapest_link1, cheapest_link2);
}
