/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:38:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/01 17:28:37 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_link	*a;
	t_link	*b;
	bool	to_free;

	a = NULL;
	b = NULL;
	to_free = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		to_free = true;
	}
	init_stack(&a, argv, to_free);
	if (is_sorted(&a, false))
		free_links(&a);
	else
	{
		find_index(a);
		push_swap(&a, &b);
	}
	return (0);
}

void	init_link(t_link **stack, int nbr, char **argv, bool to_free)
{
	t_link	*link;
	t_link	*last;

	if (stack == NULL)
		return ;
	link = (t_link *)malloc(sizeof(t_link));
	if (!link)
		ft_error(stack, argv, to_free);
	link->next = NULL;
	link->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = link;
		link->prev = NULL;
	}
	else
	{
		last = get_last_link(*stack);
		last->next = link;
		link->prev = last;
	}
}

void	init_stack(t_link **stack, char **argv, bool to_free)
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
