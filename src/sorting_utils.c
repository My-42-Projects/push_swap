/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:11:54 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/01 17:34:37 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_link	*compare_operations(t_link **stack)
{
	t_link	*current;
	t_link	*cheapest;

	current = *stack;
	cheapest = current;
	while (current)
	{
		if (current->ops < cheapest->ops)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

void	calc_total_ops(t_link **a, t_link **b, t_link *to_push)
{
	to_push->ops = to_push->pos;
	if (!(to_push->above_mid))
		to_push->ops = stack_len(*b) - to_push->pos;
	if (to_push->target->above_mid)
		to_push->ops += to_push->target->pos;
	else
		to_push->ops += stack_len(*a) - to_push->target->pos;
}

void	finish_rot(t_link **stack, t_link *to_top, char name)
{
	// static int counter = 0;

	while (*stack != to_top)
	{
		if (name == 'a')
		{
			if (to_top->above_mid)
				ra(stack);
			else
			{
				rra(stack);
				/* print_stack(*stack, "a");
				t_link	*last = get_last_link(*stack);
				t_link	*first = get_first_link(*stack);
				printf("First in stack: %d\n", first->index);
				printf("Last in stack: %d\n", last->index);
				rra(stack);
				printf("First in stack: %d\n", first->index);
				printf("Last in stack: %d\n", last->index);
				counter++;
				print_stack(*stack, "a");
				printf("To top: %d with pos %d\n", to_top->index, to_top->pos);
				if (counter == 1)
					exit(0); */
			}
		}
		else if (name == 'b')
		{
			if (to_top->above_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
