/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:51:15 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/18 10:01:08 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
