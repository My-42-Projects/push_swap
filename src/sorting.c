/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/26 11:27:36 by dulrich          ###   ########.fr       */
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

void	calc_moves_to_rotate(t_link **stack)
{
	
}

void	choose_insertion(t_link **stack, int index)
{
	t_link	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = get_last_link(stack);
	if (calc_moves_to_rotate()) //need to implement
		//rotate b;
	else
		//rev rot b;
	while (TRUE)
	{
		
		if ((*stack)->next && (((*stack)->index < index)) && (last->index > index))
			break ;
	}
	
}

void	push_cheapest(t_link **a, t_link **b, t_link *first_link, t_link *second_link)
{
	int	push_first;

	push_first = compare_moves(first_link, second_link);
	if (push_first)
	{
		while (first_link != *a)
			ra(a);
		choose_insertion(b, first_link->index);
	}
	else
	{
		while (second_link != *a)
			rra(a);
		choose_insertion(b, second_link->index);
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
