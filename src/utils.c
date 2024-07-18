/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:42:35 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/18 10:06:13 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (str[i++] - 48);
	}
	return (nbr * sign);
}

int	stack_len(t_link **stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (*stack)
	{
		*stack = (*stack)->next;
		i++;
	}
	return (i);
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

t_link	*get_last_link(t_link **head)
{
	while (*head)
		*head = (*head)->next;
	return (*head);
}
