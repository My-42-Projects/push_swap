/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:51:15 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/27 21:45:04 by dulrich          ###   ########.fr       */
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

int	partition(int *nbrs, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	pivot = nbrs[last];
	i = first;
	j = last;
	while (i < j)
	{
		while (nbrs[i] < pivot && i <= last - 1)
			i++;
		while (nbrs[j] >= pivot && j >= first + 1)
			j--;
		if (i < j)
			ft_swap(&nbrs[i], &nbrs[j]);
	}
	ft_swap(&nbrs[last], &nbrs[i]);
	return (i);
}

int	*quicksort(int *nbrs, int first, int last)
{
	int	partition_index;

	if (first < last)
	{
		partition_index = partition(nbrs, first, last);
		quicksort(nbrs, first, partition_index - 1);
		quicksort(nbrs, partition_index + 1, last);
	}
	return (nbrs);
}

int	*get_ints(t_link *stack)
{
	int	*nbrs;
	int	i;
	int	len;

	len = stack_len(&stack);
	nbrs = (int *)malloc(len * sizeof(int));
	if (!nbrs)
		ps_error(&stack);
	i = 0;
	while (stack)
	{
		nbrs[i++] = stack->nbr;
		stack = stack->next;
	}
	return (nbrs);
}

void	find_index(t_link *a)
{
	int	*unsorted;
	int	*sorted;
	int	len;

	len = stack_len(&a);
	unsorted = NULL;
	unsorted = get_ints(a);
	sorted = (int *)malloc(len * sizeof(int));
	if (!sorted)
		ps_error(&a);
	sorted = quicksort(unsorted, 0, len);
	free(unsorted);
	if (len <= 100)
		allocate_chunks(&a, sorted, 5, len / 5);
	else
		allocate_chunks(&a, sorted, 11, len / 11);
	free(sorted);
}
