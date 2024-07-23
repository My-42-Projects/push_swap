/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:51:15 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/23 18:25:35 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *nbrs, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = nbrs[high];
	i = low;
	j = high;
	while (i < j)
	{
		while (nbrs[i] < && )
	}
}

int	*quicksort(int *nbrs, int low, int high)
{
	int	partition_index;

	if (low < high)
	{
		partition_index = partition(nbrs, low, high);
		quicksort(nbrs, partition_index - 1, high);
		quicksort(nbrs, low, partition_index + 1);
	}
	return (nbrs);
}

int	*get_ints(t_link *stack)
{
	int	*nbrs;
	int	i;

	i = 0;
	while (stack)
	{
		nbrs[i++] = stack->nbr;
		stack = stack->next;
	}
	nbrs[i] = NULL;
	return (nbrs);
}

void	find_index(t_link *a)
{
	int	*unsorted;
	int	*sorted;
	int	len;

	len = stack_len(a);
	unsorted = (int *)malloc((len + 1) * sizeof(int));
	if (!unsorted)
		ft_error();
	unsorted = get_ints(a);
	sorted = (int *)malloc((len + 1) * sizeof(int));
	if (!sorted)
		ft_error();
	sorted = quicksort(unsorted, 0, len);
	free(unsorted);
	allocate_chunks(a, sorted);
	free(sorted);
}
