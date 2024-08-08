/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:11:54 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/06 21:42:14 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	compare_moves(t_link *first, t_link *second)
{
	if (second && (second->rr < first->r))
		return (0);
	else
		return (1);
}

t_link	*find_first_match(t_link **stack, t_link *link)
{
	int	r;

	if (!stack || !link)
		return (NULL);
	print_stack(*stack, "a before finding first match");
	r = 0;
	while (*stack)
	{
		if (*stack == link)
		{
			link->r = r;
			return (link);
		}
		r++;
		*stack = (*stack)->next;
	}
	return (NULL);
}

t_link	*find_second_match(t_link **stack, t_link *link)
{
	int		rr;
	t_link	*current;

	if (!stack || !link)
			return (NULL);
	rr = 0;
	current = get_last_link(*stack);
	while (current->prev)
	{
		if (current == link)
		{
			link->rr = rr + 1;
			return (link);
		}
		rr++;
		current = current->prev;
	}
	return (NULL);
}

t_link	*calc_moves_to_push(t_link **stack, t_link *link, int first)
{
	if (first)
		return(find_first_match(stack, link));
	else
		return (find_second_match(stack, link));
}
