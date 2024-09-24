/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 07:54:36 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:52:43 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_link **dest, t_link **src)
{
	t_link	*to_push;

	if (!(*src))
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
}

void	pa(t_link **a, t_link **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_link **a, t_link **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
