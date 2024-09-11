/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:37:32 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/11 14:26:28 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_link	*get_first_link(t_link *head)
{
	t_link	*current;

	if (head == NULL)
		return (NULL);
	current = head;
	while (current->prev)
		current = current->prev;
	return (current);
}

t_link	*get_last_link(t_link *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

t_link	*get_biggest_link(t_link *stack)
{
	t_link	*biggest;
	t_link	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	biggest = current;
	while (current)
	{
		if (current->index > biggest->index)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_link	*get_smallest_link(t_link *stack)
{
	t_link	*smallest;
	t_link	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	smallest = current;
	while (current)
	{
		if (current->index < smallest->index)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_link	*get_closest_link(t_link **stack, t_link *to_push)
{
	t_link	*closest;
	t_link	*current_a;
	int		best;

	best = INT_MAX;
	current_a = *stack;
	while (current_a)
	{
		if (current_a->index > to_push->index && current_a->index < best)
		{
			closest = current_a;
			best = closest->index;
		}
		current_a = current_a->next;
	}
	if (best == INT_MAX)
		closest = get_smallest_link(*stack);
	return (closest);
}
