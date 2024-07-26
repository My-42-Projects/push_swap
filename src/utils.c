/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:42:35 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/25 21:20:22 by dulrich          ###   ########.fr       */
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
	int	len;

	len = 0;
	if (stack == NULL || *stack == NULL)
		return (0);
	while (*stack)
	{
		*stack = (*stack)->next;
		len++;
	}
	return (len);
}

void	allocate_chunks(t_link **stack, int	*nbrs, int max_chunk, int	nbrs_per_chunk)
{
	int	i;
	int	j;
	int	chunk;

	i = 0;
	j = 0;
	chunk = 0;
	while (nbrs[i])
	{
		if (nbrs[i] == (*stack)->nbr)
		{
			(*stack)->index = i++;
			(*stack)->chunk = chunk;
			j++;
		}
		*stack = (*stack)->next;
		if (*stack == NULL)
			*stack = get_first_link(stack);
		if (j == nbrs_per_chunk)
		{
			j = 0;
			if (chunk != max_chunk)
				chunk++;
		}
	}
}

t_link	*get_first_link(t_link **head)
{
	while ((*head)->prev)
		*head = (*head)->prev;
	return (*head);
}

t_link	*get_last_link(t_link **head)
{
	while ((*head)->next)
		*head = (*head)->next;
	return (*head);
}
