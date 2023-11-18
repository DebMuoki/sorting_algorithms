#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - A utility function to get maximum value in array[]
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: max value in array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * count_sort - A function to do counting sort of array[] according to
 * the digit represented by exp.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: Integer to represent exponent
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int i, count[10] = {0};

	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	print_array(array, size);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}
