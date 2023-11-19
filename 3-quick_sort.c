#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - Partitions the array for quicksort.
 * @arr: Array to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: New partition index.
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	if (arr[i + 1] != arr[high])
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - Helper function for quicksort.
 * @arr: Array to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quick_sort_helper(int arr[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, size);
		quick_sort_helper(arr, low, pi - 1, size);
		quick_sort_helper(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick sort algorithm.
 * @arr: Array to sort.
 * @size: Size of the array.
 */
void quick_sort(int arr[], size_t size)
{
	if (arr == NULL || size < 2)
		return;

	quick_sort_helper(arr, 0, size - 1, size);
}

