#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
	swapped = 0;

	for (j = 0; j < size - i - 1; j++)
	{
	if (array[j] > array[j + 1])
	{
	/* Swap elements if they are in the wrong order */
	temp = array[j];
	array[j] = array[j + 1];
	array[j + 1] = temp;

	/* Set swapped to true to continue the pass */
	swapped = 1;

	/* Print the array after each swap */
	print_array(array, size);
	}
	}

	/* If no two elements were swapped by inner loop, the array is sorted */
	if (swapped == 0)
	break;
	}
}

