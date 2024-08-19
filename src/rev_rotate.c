/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:17:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/19 14:46:52 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

extern int	counter;

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

void	rrr(t_link **a, t_link **b, int times)
{
	while (times > 0)
	{
		rotate(a, TRUE);
		rotate(b, TRUE);
		write(1, "rrr\n", 4);
		times--;
		counter++;
	}
}

int	calc_rot_both(t_link **a, t_link **b, t_link *first, t_link *second)
{
	t_link	*current;
	int		i;
	int		j;

	current = *a;
	i = 0;
	while (current != first)
	{
		i++;
		current = current->next;
	}
	current = *b;
	j = 1;
	while (current != second)
	{
		j++;
		current = current->next;
	}
	if (i < j)
		return (i);
	else
		return (j);
}
