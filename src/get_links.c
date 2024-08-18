/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:37:32 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/17 21:37:39 by dulrich          ###   ########.fr       */
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

int	is_closer(int to_push, int closest, int current)
{
	if ((to_push - current) < 0)
	{
		if (((to_push - current) * -1) < (to_push - closest))
			return (1);
		else if ((to_push - closest) < 0)
		{
			if (((to_push - current) * -1) < ((to_push - closest) * -1))
				return (1);
		}
		else
			return (0);
	}
	else if ((to_push - current) < (to_push - closest))
		return (1);
	return (0);
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
			if (current->index > closest->index)
				closest = current;
			current = current->next;
		}
	}
	else
	{
		while (current)
		{
			if (is_closer(link->index, closest->index, current->index))
				closest = current;
			current = current->next;
		}
	}
	return (closest);
}
