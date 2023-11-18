#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of arr[].
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @mid: mid index where the array is divided
 * @temp: temp array to hold the merged array
 */
void merge(int *array, int size, int mid, int *temp)
{
	int i = 0;
	int j = mid;
	int k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	while (i < mid && j < size)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < size)
		temp[k++] = array[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int mid;
	int *temp = malloc(sizeof(int) * size);

	if (!temp)
		return;

	if (size < 2)
	{
		free(temp);
		return;
	}

	mid = size / 2;
	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, size, mid, temp);

	free(temp);
}
