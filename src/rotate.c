/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:56:25 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/08 13:57:11 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//works
void	rotate(t_link **stack, int reverse)
{
	t_link	*last;
	t_link	*head;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	head = *stack;
	last = get_last_link(*stack);
	if (!reverse)
	{
		last->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next->prev = last;
		last->next->next = NULL;
	}
	else
	{
		while (head)
        {
            if (head->next->next == NULL)
            {
                head->next = NULL;
                break ;
            }
            head = head->next;
        }
        last->next = *stack;
    	*stack = last;
	}
}

/* void	rotate(t_link **stack, int reverse)
{
	t_link	*last;
	t_link	*tmp1;
	t_link	*tmp2;
	t_link	*penultimate;

	if (stack == NULL || *stack == NULL || stack_len(*stack) == 1)
		return ;
	last = get_last_link(*stack);
	if (!reverse)
	{
		last->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next->prev = last;
		last->next->next = NULL;
	}
	else
	{
		penultimate = last->prev;
		tmp1 = last;
		last = penultimate;
		last->next = NULL;
		tmp2 = *stack;
		*stack = tmp1;
		(*stack)->next = tmp2;
	}
} */

		/* 
		tmp1 = *stack;
		*stack = (*stack)->next;
		tmp1->next = NULL;
		last->next = NULL;
		
		penultimate = last->prev;
		tmp = *stack;
		*stack = last;
		(*stack)->next = tmp;
		last = penultimate;
		penultimate->next = NULL; */

void	ra(t_link **a)
{
	rotate(a, false);
	write(1, "ra\n", 3);
}

void	rb(t_link **b)
{
	rotate(b, false);
	write(1, "rb\n", 3);
}

void	rr(t_link **a, t_link **b)
{
	rotate(a, false);
	rotate(b, false);
	write(1, "rr\n", 3);
}

void	rotate_both(t_link **a, t_link **b, t_link *link, bool reverse)
{
	if (reverse)
	{
		while (*a != link->target && *b != link)
			rrr(a, b);
	}
	else
	{
		while (*a != link->target && *b != link)
			rr(a, b);
	}
	find_pos(*a);
	find_pos(*b);
}
