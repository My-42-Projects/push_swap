/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:51:38 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:51:54 by dulrich          ###   ########.fr       */
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
	push_cheapest(a, b, cheapest_link);
}
