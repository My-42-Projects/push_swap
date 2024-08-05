/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:42:35 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/05 20:43:28 by dulrich          ###   ########.fr       */
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
	nbr = 0;
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

int	stack_len(t_link *stack)
{
	int	len;

	len = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	allocate_chunks(t_link **stack, int	*nbrs, int max_chunk, int nbrs_per_chunk)
{
	int	i;
	int	j;
	int	len;
	int	chunk;
	t_link	*head;

	i = 0;
	j = 0;
	chunk = 1;
	len = stack_len(*stack);
	head = get_first_link(*stack);
	if (*stack == NULL)
		*stack = head;
	while (i < len)
	{
		if ((*stack)->next == NULL)
			*stack = head;
		else
			*stack = (*stack)->next;
		if (nbrs[i] == (*stack)->nbr)
		{
			if (i == 0)
				(*stack)->smallest = TRUE;
			i++;
			j++;
			(*stack)->index = i;
			(*stack)->chunk = chunk;
			if (i == len)
				(*stack)->biggest = TRUE;
		}
		if (j == nbrs_per_chunk)
		{
			j = 0;
			if (chunk < max_chunk)
				chunk++;
		}
	}
	printf("Chunks alloc'd\n");
}

t_link	*get_first_link(t_link *head)
{
	while (head->prev)
		head = head->prev;
	return (head);
}

t_link	*get_last_link(t_link *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
