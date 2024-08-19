/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:00:14 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/18 19:30:59 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	determine_rotation(t_link **stack, t_link *link)
{
	t_link	*current;
	int	rot;
	int	mid;

	mid = stack_len(*stack) / 2;
	current = *stack;
	rot = -1;
	while (current)
	{
		rot++;
		if (current == link)
			break ;
		current = current->next;
	}
	if (rot <= mid)
		return (1);
	else
		return (0);
}

void	last_rotation(t_link **stack)
{
	t_link	*biggest;
	t_link	*current;
	int		norm_rot;

	biggest = get_biggest_link(*stack);
	norm_rot = determine_rotation(stack, biggest);
	current = *stack;
	while (current != biggest)
	{
		if (norm_rot)
			rb(stack);
		else
			rrb(stack);
		current = *stack;
	}
}

void	allocate_chunks(t_link **stack, int	*nbrs, int max_chunk, int nbrs_per_chunk)
{
	int	i;
	int	j;
	int	len;
	int	chunk;
	t_link	*head;

	i = 0;
	j = 0;
	chunk = 0;
	len = stack_len(*stack);
	head = get_first_link(*stack);
	if (*stack == NULL)
		*stack = head;
	while (i < len)
	{
		if ((*stack)->next == NULL)
			*stack = head;
		else
			*stack = (*stack)->next;
		if (nbrs[i] == (*stack)->nbr)
		{
			if (i == 0)
				(*stack)->smallest = TRUE;
			i++;
			j++;
			(*stack)->index = i;
			(*stack)->chunk = chunk;
			if (i == len)
				(*stack)->biggest = TRUE;
		}
		if (j == nbrs_per_chunk)
		{
			j = 0;
			if (chunk < max_chunk)
				chunk++;
		}
	}
}
