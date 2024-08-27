/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:38:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/27 06:16:10 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_link(t_link **stack, int nbr, char **argv, int to_free)
{
	t_link	*new_link;
	t_link	*last_link;

	new_link = (t_link *)malloc(sizeof(t_link));
	if (!new_link)
		ft_error(stack, argv, to_free);
	new_link->nbr = nbr;
	new_link->next = NULL;
	new_link->index = 0;
	new_link->chunk = 0;
	new_link->r = 0;
	new_link->rr = 0;
	new_link->reverse = FALSE;
	new_link->smallest = 0;
	new_link->biggest = 0;
	new_link->ops = 0;
	new_link->target_r = 0;
	new_link->target_rr = 0;
	new_link->target = 0;
	if (*stack == NULL)
	{
		*stack = new_link;
		new_link->prev = NULL;
	}
	else
	{
		last_link = get_last_link(*stack);
		last_link->next = new_link;
		new_link->prev = last_link;
	}
}

void	init_stack(t_link **stack, char **argv, int to_free)
{
	int		i;
	long	nbr;

	i = 1;
	if (to_free)
		i = 0;
	nbr = 0;
	while (argv[i])
	{
		if (is_syntax_error(argv[i]))
			ft_error(stack, argv, to_free);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(stack, argv, to_free);
		if (is_duplicate(*stack, (int)nbr))
			ft_error(stack, argv, to_free);
		init_link(stack, (int)nbr, argv, to_free);
		i++;
	}
	if (to_free)
		free_artificial_argv(argv);
}

int	main(int argc, char **argv)
{
	t_link	*a;
	t_link	*b;
	int		to_free;

	a = NULL;
	b = NULL;
	to_free = FALSE;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		to_free = TRUE;
	}
	init_stack(&a, argv, to_free);
	if (is_sorted(&a, FALSE))
		free_links(&a);
	else
	{
		find_index(a);
		push_swap(&a, &b);
	}
	return (0);
}
