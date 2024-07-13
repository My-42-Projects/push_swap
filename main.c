/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:38:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/13 11:46:52 by dulrich          ###   ########.fr       */
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

int	chunk_is_done(t_link **head, int chunk)
{
	while (*head)
	{
		if ((*head)->chunk == chunk)
			return (0);
		*head = (*head)->next;
	}
	return (1);
}

void	sort_100(t_link **a, t_link **b)
{
	int	chunk;
	int	stack_len_a;

	chunk = 1;
	stack_len_a = stack_len(a);
	while (stack_len_a)
	{
		get_cheapest_link(a, b, chunk);
		if (chunk_is_done(a, chunk))
			chunk++;
		stack_len_a--;
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

t_link	*clone_stack(t_link **a, t_link **c)
{
	int		i;
	int		*values;

	while (*a)
	{
		init_link(c, (*a)->nbr);
		*a = (*a)->next;
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
		init_link(stack, (int)nbr);
		i++;
	}
	if (flag)
		free_artificial_argv(argv);
}

t_link	*navigate_to_last_link(t_link **head)
{
	while (*head)
		*head = (*head)->next;
	return (*head);
}

int	compare_moves(t_link *first, t_link *second)
{
	if (first)
	{
		if (second && (second->rrr < first->rr))
			return (0);
		else
			return (1);
	}
}

t_link	*find_first_match(t_link **stack, t_link *link)
{
	int	rr;

	rr = 0;
	while (*stack)
	{
		if (link == *stack)
		{
			link->rr = rr;
			return (link);
		}
		rr++;
		*stack = (*stack)->next;
	}
}

t_link	*find_second_match(t_link **stack, t_link *link)
{
	int	rrr;

	rrr = 0;
	while (*stack)
	{
		if (link == *stack)
		{
			link->rrr = rrr;
			return (link);
		}
		rrr++;
		*stack = (*stack)->next;
	}
}

t_link	*calc_moves_to_push(t_link **stack, t_link *link, int flag)
{
	int	rrr;
	t_link	*first_link;
	t_link	*last_link;

	if (flag)
		return(first_link = find_first_match(stack, link));
	else
	{
		last_link = find_second_match(stack, link);
		if (compare_moves(link, last_link))
			return (link);
		else
			return (last_link);
	}
}

void	push_cheapest(t_link **a, t_link **b, t_link *cheapest_node)
{
	
}

void	get_cheapest_link(t_link **a, t_link **b, int chunk)
{
	t_link	*cheapest_node;
	t_link	*cheapest_node2;

	cheapest_node = NULL;
	cheapest_node2 = NULL;
	while (*a)
	{
		if ((*a)->chunk == chunk)
			cheapest_node = calc_moves_to_push(a, *a, 1);
		if (cheapest_node)
		{
			navigate_to_last_link(a);
			while (*a != cheapest_node)
			{
				if ((*a)->chunk == chunk)
				{
					cheapest_node2 = calc_moves_to_push(a, *a, 0);
					break ;
				}
				*a = (*a)->prev;
			}
		}
		*a = (*a)->next;
	}
	push_cheapest(a, b, cheapest_node);
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