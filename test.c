#include "stdio.h"

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

int	main(void)
{
	int arr[] = {5, 2, 4, 18, 10, 4, 5, 2, 4, 18, 10, 4};
	int i = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	//int	len = arr_len(arr);
	int	chunks = 5;
	int len = sizeof(arr) / sizeof(arr[0]);
	int	n_per_chunk = len / chunks;

	/* printf("Unsorted: \n");
	while (i < n)
	{
		printf("%i,", arr[i]);
		i++;
	}
	printf("\nSorted: \n");
	quicksort(arr, 0, n - 1);
	i = 0;
	while (i < n)
	{
		printf("%i,", arr[i]);
		i++;
	} */
	printf("Len: %i and nbr per chunk: %i", len, n_per_chunk);
	return (0);
}