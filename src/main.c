/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:38:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/25 21:36:49 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_link(t_link *stack, int nbr, char **argv, int flag)
{
	t_link	*new_link;

	new_link = (t_link *)malloc(sizeof(t_link));
	if (!new_link)
		ft_error(stack, argv, flag);
	new_link->nbr = nbr;
	new_link->prev = stack;
	new_link->next = NULL;
	new_link->index = 0;
	new_link->chunk = 0;
	new_link->rr = 0;
	new_link->rrr = 0;
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