/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:38:37 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/05 20:07:14 by dulrich          ###   ########.fr       */
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
	new_link->rr = 0;
	new_link->rrr = 0;
	new_link->smallest = 0;
	new_link->biggest = 0;
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
	nbr = 0;
	while (argv[i])
	{
		if (is_syntax_error(argv[i]))
		{
			printf("syntax\n");
			ft_error(stack, argv, to_free);
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			printf("min/max");
			ft_error(stack, argv, to_free);
		}
		if (is_duplicate(*stack, (int)nbr))
		{
			printf("dup");
			ft_error(stack, argv, to_free);
		}
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
	if (argc <= 1)
		return (1);
	else if (argc == 2 && argv[1][0])
	{
		argv = ft_split(argv[1], ' ');
		to_free = TRUE;
	}
	init_stack(&a, argv, to_free);
	if (is_sorted(a, FALSE))
		free_links(&a);
	else
	{
		find_index(a);
		push_swap(&a, &b);
	}
	return (0);
}
