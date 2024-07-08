/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:38:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/08 21:18:45 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_link **a, t_link **b)
{
	/* 
	Push everything but three nbrs to stack b
	Then calculate the nbr of moves necessary to get each item in its correct position
	Do the one with the least nbr of moves first
	 */
	if (stack_len(a) <= 3)
		sort_three(a);
	else if (stack_len(a) <= 5)
		sort_five(a, b);
	else if (stack_len(a) <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);
}

void	sort_100(t_link *a, t_link *b)
{
	int	;

	= 0;
	while (a)
	{
		find_min_values(a, b);
		
	}
}

void	sort_five(t_link *a, t_link *b)
{
	pb(a);
	if (stack_len(a) == 5)
		pb(a);
	sort_three(a);
	if (b->nbr > b->next->nbr)
			sb(b);
	while (b)
	{
		while (b->nbr > a->nbr && b->nbr < a->next->nbr)
			ra(a);
		pa(b);
		b = b->next;
	}
}

void	sort_three(t_link *stack)
{
	if (stack_len(stack) == 2)
		sa();
	else if ((stack->nbr > stack->next->nbr) && 
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

int	is_sorted(t_link *stack)
{
	while (stack)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_link *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_link	*clone_stack(t_link *a, t_link *c)
{
	int		i;
	int		*values;

	while (a)
	{
		init_link(c, a->nbr);
		a = a->next;
	}
	return (c);
}

void	find_index(t_link *a)
{
	t_link	*c;

	c = NULL;
	c = clone_stack(a, c);
	quicksort(c);
	a = a->prev;
	while (c)
	{
		a = a->next;
		if (c->nbr == a->nbr)
		{
			a->index = c->index;
			a->chunk = c->chunk;
			c = c->next;
		}
	}
	free_links(c);
}

void	ft_error(t_link **stack, char **argv, int flag)
{
	write(STDERR_FILENO, "Error\n", 6);
	/* 
	- Free everything (nodes and artificial argv if used)
	- exit
	 */
	free_links();
	if (flag)
		free_artificial_argv(argv);
	exit(EXIT_FAILURE);
}

void	init_link(t_link *stack, int nbr)
{
	t_link	*new_node;

	new_node = (t_link *)malloc(sizeof(t_link));
	if (!new_node)
		ft_error();
	new_node->nbr = nbr;
	new_node->prev = stack;
	new_node->next = NULL;
	new_node->index = 0;
	new_node->chunk = 0;
}

int	is_syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(t_link *stack, int nbr)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->nbr == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
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
		init_link(stack, (int)nbr);
		i++;
	}
	if (flag)
		free_artificial_argv(argv);
}

int	find_min_values(t_link **a, t_link **b)
{
	/* 
	Search from the top for smallest value of current chunk
	Then do the same from the bottom
	Compare the nbr of moves needed and push the one with fewer moves to b
	 */
	push_cheapest(a, b);
}

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
	if (!is_sorted(a))
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