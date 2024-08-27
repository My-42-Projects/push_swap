/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:17:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/27 15:44:38 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_link **a)
{
	rotate(a, TRUE);
	write(1, "rra\n", 4);
}

void	rrb(t_link **b)
{
	rotate(b, TRUE);
	write(1, "rrb\n", 4);
}

void	rrr(t_link **a, t_link **b)
{
	rotate(a, TRUE);
	rotate(b, TRUE);
	write(1, "rrr\n", 4);
}

int	calc_rev_rot_both(t_link *first, t_link *second)
{
	if (first->rr < second->target_rr ||
		first->rr == second->target_rr)
		return (first->rr);
	else if (second->target_rr < first->rr)
		return (second->target_rr);
	else
		return (0);
}

int	calc_rot_both(t_link *first, t_link *second)
{
	if (first->reverse)
		return (calc_rev_rot_both(first, second));
	if (first->r < second->target_r ||
		first->r == second->target_r)
		return (first->r);
	else if (second->target_r < first->r)
		return (second->target_r);
	else
		return (0);
}
