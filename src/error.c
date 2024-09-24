/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:53:35 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:52:10 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(t_link **stack, char **argv, int flag)
{
	write(STDERR_FILENO, "Error\n", 6);
	free_links(stack);
	if (flag)
		free_artificial_argv(argv);
	exit(EXIT_FAILURE);
}

void	ps_error(t_link **stack)
{
	write(STDERR_FILENO, "Error\n", 6);
	free_links(stack);
	exit(EXIT_FAILURE);
}
