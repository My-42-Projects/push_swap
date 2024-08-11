/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:37:32 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/11 15:47:43 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_link	*get_first_link(t_link *head)
{
	while (head->prev)
		head = head->prev;
	return (head);
}

t_link	*get_last_link(t_link *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_link	*get_biggest_link(t_link *stack)
{
	t_link	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->index > biggest->index)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_link	*get_smallest_link(t_link *stack)
{
	t_link	*smallest;
	
	smallest = stack;
	while (stack)
	{
		if (stack->index < smallest->index)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_link	*get_closest_link(t_link **stack, t_link *link, int is_bigger)
{
	t_link	*closest;
	t_link	*current;

	closest = *stack;
	current = *stack;
	if (is_bigger)
	{
		while (current)
		{
			if (current->index < link->index && current->index > closest->index)
				closest = current;
			current = current->next;
		}
	}
	else
	{
		while (current)
		{
			if (current->index > link->index && current->index < closest->index)
				closest = current;
			current = current->next;
		}
	}
	return (closest);
}
