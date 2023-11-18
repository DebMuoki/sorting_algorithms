#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * hoare_partition - Partitions the array for quicksort.
 * @array: Array to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: New partition index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_helper - Helper function for quicksort.
 * @array: Array to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quick_sort_hoare_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = hoare_partition(array, low, high, size);

		quick_sort_hoare_helper(array, low, pi, size);
		quick_sort_hoare_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * @array: Array to sort.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_hoare_helper(array, 0, size - 1, size);
}

