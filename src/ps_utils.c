/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:00:14 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/18 10:08:48 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	chunk_is_done(t_link **head, int chunk)
{
	while (*head)
	{
		if ((*head)->chunk == chunk)
			return (0);
		*head = (*head)->next;
	}
	return (1);
}
