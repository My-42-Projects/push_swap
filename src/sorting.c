/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/30 21:25:06 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_insertion(t_link **stack, t_link *link)
{
	t_link	*last;
	int		reverse;

	if (!(*stack) || !(*stack)->next)
		return ;
	reverse = 0;
	last = get_last_link(*stack);
	if (ft_strncmp(determine_rotation(stack, link), "rrr", 3) == 0)
		reverse = 1;
	while (TRUE)
	{
		if (reverse)
			rrb(stack);
		else
			rb(stack);
		if ((*stack)->next && (((*stack)->index < link->index)) && (last->index > link->index))
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
		choose_insertion(b, first_link);
	}
	else
	{
		while (second_link != *a)
			rra(a);
		choose_insertion(b, second_link);
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
			get_last_link(*a);
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
