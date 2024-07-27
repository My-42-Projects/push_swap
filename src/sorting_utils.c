/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:11:54 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/27 21:55:27 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_link	*find_first_match(t_link **stack, t_link *link)
{
	int	rr;

	if (!stack || !(*stack) || !link)
		return (NULL);
	rr = 0;
	while (*stack)
	{
		if (link == *stack)
		{
			link->rr = rr;
			return (link);
		}
		rr++;
		*stack = (*stack)->next;
	}
	return (NULL);
}

t_link	*find_second_match(t_link **stack, t_link *link)
{
	int	rrr;

	if (!stack || !(*stack) || !link)
			return (NULL);	
	rrr = 0;
	while (*stack)
	{
		if (link == *stack)
		{
			link->rrr = rrr;
			return (link);
		}
		rrr++;
		*stack = (*stack)->next;
	}
	return (NULL);
}

int	compare_moves(t_link *first, t_link *second)
{
	if (second && (second->rrr < first->rr))
		return (0);
	else
		return (1);
}

t_link	*calc_moves_to_push(t_link **stack, t_link *link, int flag)
{
	if (flag)
		return(find_first_match(stack, link));
	else
		return (find_second_match(stack, link));
}
