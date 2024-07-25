/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:38:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/25 13:51:56 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* void	sort_b(t_link **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	while (TRUE)
	{
		if ((*stack)->next && ((*stack)->index < (*stack)->next->index))
		{
			calc_moves_to_rotate();
			#rotate or reverse rotate b;
		}
		if (is_sorted(stack))
			break ;
	}
} */

void	init_link(t_link *stack, int nbr, char **argv, int flag)
{
	t_link	*new_node;

	new_node = (t_link *)malloc(sizeof(t_link));
	if (!new_node)
		ft_error(stack, argv, flag);
	new_node->nbr = nbr;
	new_node->prev = stack;
	new_node->next = NULL;
	new_node->index = 0;
	new_node->chunk = 0;
	new_node->rr = 0;
	new_node->rrr = 0;
}

void	init_stack(t_link **stack, char **argv, int flag)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (argv[i])
	{
		if (is_syntax_error(argv[i]))
			ft_error(stack, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(stack, argv, flag);
		if (is_duplicate(stack, (int)nbr))
			ft_error(stack, argv, flag);
		init_link(stack, (int)nbr, argv, flag);
		i++;
	}
	if (flag)
		free_artificial_argv(argv);
}

char	*determine_rotation(t_link **stack, t_link *link)
{
	int	rot;
	int	mid;

	mid = stack_len(stack) / 2;
	rot = 0;
	while (*stack)
	{
		if (*stack == link)
			break ;
		rot++;
	}
	if (rot <= mid)
		return ("rr");
	else
		return ("rrr");
}
/*
to make it more efficient I need to determine if I should rotate or rev rot
void	choose_insert(t_link **stack, int index)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	while (TRUE)
	{
		if ((*stack)->next && ((*stack)->index < (*stack)->next->index))
		{
			if (calc_moves_to_rotate(stack, index) == 1)
				rb();
			else
				rrb();
		}
		if (is_sorted(stack))
			break ;
	}
} */

int	main(int argc, char **argv)
{
	t_link	*a;
	t_link	*b;
	int		flag;

	a = NULL;
	b = NULL;
	flag = 0;
	if (argc <= 2)
	{
		if (argc == 2 && argv[1][0])
			argv = ft_split(argv[1], ' ');
		else
			exit (EXIT_FAILURE);
		flag = 1;
	}
	init_stack(a, argv, flag);
	find_index(a);
	if (!is_sorted(a, FALSE))
		push_swap(a, b);
	return (0);
}

/* 
Copy stack a to stack c and run quicksort for example
When sorted assign each node the correct index nbr

Idea: To push everything to b in more or less ascending order
Implement different conditions for <=5 <=100 (5 chunks) and <=500 nbrs (11 chunks)
Find out which values belong in which chunks --> run search algorith over it and index the nodes
Go through the chunks and find the first two corresponding values
Compare, which needs fewer moves and push to b
 */