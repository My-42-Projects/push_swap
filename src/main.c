/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:08 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/01 10:04:30 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**artificial_argv()
{
	
}

void	push_swap(t_node **a, t_node **b)
{
	
}

void	sort_five(t_node *a, t_node *b)
{
	/* 
	push two nodes to stack b
	do sort_three
	
	 */
}

void	sort_three(t_node *stack)
{
	if ((stack->nbr > stack->next->nbr) && 
	(stack->nbr > stack->next->next->nbr))
	{
		ra();
		if (stack->next->nbr > stack->next->next->nbr)
			sa();
	}
	else if ((stack->next->nbr > stack->nbr) && 
	(stack->next->nbr > stack->nbr))
	{
		rra();
		if (stack->next->next->nbr > stack->nbr)
			sa();
	}
	else if ((stack->next->next->nbr > stack->nbr) &&
			(stack->next->next->nbr > stack->next->nbr))
	{
		if (stack->nbr > stack->next->nbr)
			sa();
	}
}

t_node	**clone_stack(t_node **a)
{
	
}

void	find_index(t_node **a)
{
	t_node	**c;

	c = NULL;
	c = clone_stack(a);
	quicksort(c);
}

void	ft_error()
{
	
	write(STDERR_FILENO, "Error\n", 6);
}

char	**artificial_argv(char *str)
{
	/* 
	
	 */
}

int	main(int argc, char **argv)
{
	t_node	**a;
	t_node	**b;
	char	**art_argv;

	a = NULL;
	b = NULL;
	if (argc <= 2)
	{
		if (argc == 2)
			art_argv = artificial_argv(argv[1]);
		else
			return (1);
	}
	init_nodes(a, argv, argc == 2);
	find_index(a);
	if (!is_sorted(a))
	{
		if (a == 3)
			sort_three(a);
		else if (a == 5)
			sort_five(a, b);
		else
			push_swap(a, b);
	}
	return (0);
}

/* 
Copy stack a to stack c and run quicksort for example
When sorted assign each node the correct index nbr
 */