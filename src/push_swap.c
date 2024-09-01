/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:46 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/01 17:39:42 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_link **a, t_link **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		sa(a);
	/* if (len <= 5)
		sort_five(a, b, len); */
	else
		sort_all(a, b);
	print_stack(*a, "a after sorting");
	print_stack(*b, "b after sorting");
	free_links(a);
}

//not complete
/* void	sort_five(t_link **a, t_link **b, int len)
{

	while (len-- > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
		get_cheapest_link(a, b);
	if (!is_sorted())
		last_rotation();
} */

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
