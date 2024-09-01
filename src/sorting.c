/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/01 17:34:33 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_cheapest(t_link **a, t_link **b, t_link *to_push)
{
	if (to_push->above_mid && to_push->target->above_mid)
		rotate_both(a, b, to_push, false);
	else if (!(to_push->above_mid) && !(to_push->target->above_mid))
		rotate_both(a, b, to_push, true);
	finish_rot(b, to_push, 'b');
	finish_rot(a, to_push->target, 'a');
	pa(a, b);
}

void	get_cheapest_link(t_link **a, t_link **b)
{
	t_link	*current_b;
	t_link	*cheapest_link;

	current_b = *b;
	while (current_b)
	{
		current_b->target = get_closest_link(a, current_b);
		calc_total_ops(a, b, current_b);
		current_b = current_b->next;
	}
	cheapest_link = compare_operations(b);
	print_stack(*b, "b");
	print_stack(*a, "a");
	printf("Cheapest link: %d with %d ops and is above mid %d\n", cheapest_link->index, cheapest_link->ops, cheapest_link->above_mid);
	printf("Target link: %d and is above mid %d\n", cheapest_link->target->index, cheapest_link->target->above_mid);
	push_cheapest(a, b, cheapest_link);
}
