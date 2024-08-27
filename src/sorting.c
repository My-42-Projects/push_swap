/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/26 19:17:04 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	finish_rot(t_link **a, t_link **b, t_link *to_push, t_link *target)
{
	if (to_push->reverse)
	{
		while (to_push->rr > 0)
		{
			rra(a);
			to_push->rr--;
		}
		while (target->target_rr > 0)
		{
			rrb(b);
			target->target_rr--;
		}
	}
	else
	{
		while (to_push->r > 0)
		{
			ra(a);
			to_push->r--;
		}
		while (target->target_r > 0)
		{
			rb(b);
			target->target_r--;
		}
	}
}

void	push_cheapest(t_link **a, t_link **b, t_link *to_push, t_link *target)
{
	int		times;
	
	times = calc_rot_both(to_push, target);
	rotate_both(a, b, to_push, target, times);
	finish_rot(a, b, to_push, target);
	pb(a, b);
}

void	find_target_above_mid(t_link *target, t_link **stack, int is_bigger)
{
	t_link	*current;
	int		i;

	i = 1;
	if (is_bigger)
		i = 0;
	current = *stack;
	while (current != target)
	{
		current = current->next;
		i++;
	}
	target->target_r = i;
}

void	find_target_below_mid(t_link *target, t_link **stack, int is_bigger)
{
	t_link	*current;
	int		i;

	i = 0;
	if (is_bigger)
		i = 1;
	current = get_last_link(*stack);
	while (current != target)
	{
		current = current->prev;
		i++;
	}
	target->target_rr = i;
}

int	calc_remaining_ops(t_link *link, t_link *target, int i)
{
	if (i > 0)
	{
		if (link->reverse)
		{
			if (i == link->rr && i != target->target_rr)
				i += target->target_rr;
			else if (i == target->target_rr && i != link->rr)
				i += link->rr;
		}
		else
		{
			if (i == link->rr && i != target->target_rr)
				i += target->target_rr;
			else if (i == target->target_rr && i != link->rr)
				i += link->rr;
		}
	}
	return (i);
}

int	place_in_b(t_link *link, t_link *target, t_link **stack, int is_bigger)
{
	int	i;

	i = 0;
	if (determine_rotation(stack, target))
		find_target_above_mid(target, stack, is_bigger);
	else
		find_target_below_mid(target, stack, is_bigger);
	i += calc_rot_both(link, target);
	i += calc_remaining_ops(link, target, i);
	return (i);
}


void	find_correct_position(t_link **b, t_link *link)
{
	t_link	*biggest;
	t_link	*target;
	int		ops;

	biggest = get_biggest_link(*b);
	target = get_closest_link(b, link, FALSE);
	ops = 1;
	if (link->index > biggest->index)
	{
		ops += place_in_b(link, biggest, b, TRUE); //biggest nbr must be at the top
		link->target = biggest->index;
	}
	else
	{
		ops += place_in_b(link, target, b, FALSE); //next smallest nbr must be at the bottom
		link->target = target->index;	
	}
	link->ops = ops;
}

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

void	moves_to_top_of_a(t_link **stack, t_link *link)
{
	int		i;
	t_link	*target_pos;

	i = 0;
	if (!determine_rotation(stack, link))
	{
		target_pos = get_last_link(*stack);
		while (link != target_pos)
		{
			target_pos = target_pos->prev;
			i++;
		}
		link->rr = ++i;
		link->reverse = TRUE;
	}
	else
	{
		target_pos = *stack;
		while (link != target_pos)
		{
			target_pos = target_pos->next;
			i++;
		}
		link->r = i;
	}
}

t_link	*get_target(t_link **stack, t_link *to_push)
{
	t_link	*target;
	int		index;

	index = to_push->target;
	target = *stack;
	while (target->index != index)
		target = target->next;
	return (target);
}

void	get_cheapest_link(t_link **a, t_link **b)
{
	t_link	*current;
	t_link	*cheapest_link;
	t_link	*target;

	current = *a;
	while (current)
	{
		moves_to_top_of_a(a, current);
		find_correct_position(b, current);
		current = current->next;
	}
	cheapest_link = compare_operations(a);
	target = get_target(b, cheapest_link);
	print_stack(*a, "a");
	printf("Cheapest link: %d with %d ops\n", cheapest_link->index, cheapest_link->ops);
	printf("Target link: %d\n", target->index);
	push_cheapest(a, b, cheapest_link, target);
}
