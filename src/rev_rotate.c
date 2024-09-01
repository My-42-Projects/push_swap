/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:17:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/01 17:31:10 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_link **a)
{
	rotate(a, true);
	write(1, "rra\n", 4);
}

void	rrb(t_link **b)
{
	rotate(b, true);
	write(1, "rrb\n", 4);
}

void	rrr(t_link **a, t_link **b)
{
	rotate(a, true);
	rotate(b, true);
	write(1, "rrr\n", 4);
}
