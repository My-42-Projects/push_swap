/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:46 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/11 14:14:49 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_link **a, t_link **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		sa(a);
	else
		sort_all(a, b);
	free_links(a);
}

void	sort_all(t_link **a, t_link **b)
{
	while (stack_len(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		find_pos(*a);
		find_pos(*b);
		get_cheapest_link(a, b);
	}
	find_pos(*a);
	if (!is_sorted(a, false))
		last_rotation(a);
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
