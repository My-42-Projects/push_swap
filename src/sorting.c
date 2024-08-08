/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:50:33 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/08 16:30:28 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Make it more efficient by finding out, which way to rotate
void	choose_insertion(t_link **stack, t_link *link)
{
	t_link	*last;
	t_link	*current;
	t_link	*biggest;
	t_link	*smallest;
	t_link	*closest;
	// int		reverse;

	if (stack == NULL || !(*stack)->next)
		return ;
	/* reverse = FALSE;
	if (ft_strncmp(determine_rotation(stack, link), "rr", 2) == 0)
		reverse = TRUE; */
	biggest = get_biggest_link(*stack);
	smallest = get_smallest_link(*stack);
	closest = NULL;
	if (link->index > biggest->index)
		closest = get_closest_link(stack, link, 1);
	else if (link->index < smallest->index)
		closest = get_closest_link(stack, link, 0);
	if (closest != NULL)
	{
		while (*stack != closest)
			rb(stack);
		return ;
	}
	while (TRUE)
	{
		current = *stack;
		last = get_last_link(*stack);
		if (current->index < link->index && last->index > link->index)
			break ;
		else
			rb(stack);
	}
}

//Rotate or rev rot **a until the link to push is at the top,
//then find where to insert it into **b
//lastly, rotate **b to the correct spot and then push
void	push_cheapest(t_link **a, t_link **b, t_link *first, t_link *second)
{
	int		push_first;

	push_first = compare_moves(first, second);
	if (push_first)
	{
		printf("3\n");
		while (first != *a)
			ra(a);
		print_stack(*a, "a after rotating & before insertion");
		choose_insertion(b, first);
	}
	else
	{
		printf("4\n");
		while (second != *a)
			rra(a);
		printf("After rev rotating & before insertion\n");
		choose_insertion(b, second);
	}
	print_stack(*a, "a");
	print_stack(*b, "b");
	pb(a, b);
}

//Find the cheapest link to push from **a to **b
void	get_cheapest_link(t_link **a, t_link **b, int chunk)
{
	t_link	*cheapest_link1;
	t_link	*cheapest_link2;
	t_link	*current;
	int		i;

	i = 0;
	cheapest_link1 = NULL;
	cheapest_link2 = NULL;
	printf("%d\n", chunk);
	print_stack(*a, "a before getting cheapest link");
	/* while (current)
	{
		printf("%d is in chunk %d\n", current->nbr, current->chunk);
		current = current->next;
	} */
	current = get_first_link(*a);
	while (current)
	{
		if (current->chunk == chunk)
		{
			printf("Finding first link\n");
			cheapest_link1 = calc_moves_to_push(a, current, TRUE);
			printf("Cheapest_link1->nbr: %d\n", cheapest_link1->nbr);
		}
		if (cheapest_link1 != NULL)
		{
			printf("%d\n", cheapest_link1->nbr);
			current = get_last_link(*a);
			while (current != cheapest_link1)
			{
				if (current->chunk == chunk)
				{
					printf("Finding second link\n");
					cheapest_link2 = calc_moves_to_push(a, current, FALSE);
					break ;
				}
				current = current->prev;
			}
		}
		current = current->next;
		// print_stack(*a, "a after one round of get_cheapest_link");
		printf("Current->nbr: %d\n", current->nbr);
		i++;
		printf("Rounds gone: %d\n", i);
		if (i == 10)
			exit (1);
	}
	push_cheapest(a, b, cheapest_link1, cheapest_link2);
}
