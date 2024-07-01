/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:08 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/01 13:42:20 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**artificial_argv()
{
	
}

void	push_swap(t_node **a, t_node **b)
{
	
}

void	sort_five(t_node **a, t_node **b)
{
	/* 
	push two nodes to stack b
	do sort_three
	
	 */
	pb(a);
	pb(a);
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

int	is_sorted(t_node *stack)
{
	
}

t_node	**clone_stack(t_node *a)
{
	
}

void	find_index(t_node *a)
{
	t_node	**c;

	c = NULL;
	c = clone_stack(a);
	quicksort(c);
	
}

void	ft_error()
{
	write(STDERR_FILENO, "Error\n", 6);
	/* 
	- Free everything (nodes and artificial argv if used)
	- exit
	 */
	exit(EXIT_FAILURE);
}

void	init_stack(t_node **stack, char **argv, int flag)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (argv[i])
	{
		if (is_syntax_error(argv[i]))
			ft_error();
		if (is_duplicate(argv[i]))
			ft_error();
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error();
		init_node();
		i++;
	}
	if (flag)
		free_artificial_argv(argv);
}

int	main(int argc, char **argv)
{
	t_node	**a;
	t_node	**b;
	int		flag;

	a = NULL;
	b = NULL;
	flag = 0;
	if (argc <= 2)
	{
		if (argc == 2)
			argv = ft_split(argv[1], ' ');
		else
			exit (EXIT_FAILURE);
		flag = 1;
	}
	init_stack(a, argv, flag);
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