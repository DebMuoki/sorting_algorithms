#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in the array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Builds a heap from a given array.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 * @i: The index of the current node.
 */
void heapify(int *array, size_t size, int i)
{
	int max = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;

	if (left_child < (int)size && array[left_child] > array[max])
		max = left_child;

	if (right_child < (int)size && array[right_child] > array[max])
		max = right_child;

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		heapify(array, size, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap sort algorithm
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0);
	}
}
