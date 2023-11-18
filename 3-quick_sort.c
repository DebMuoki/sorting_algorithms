#include "sort.h"

/* Function prototypes */
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Lomuto partition scheme.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: Function that implements the Quick Sort algorithm.
 * It sorts the given array in ascending order and prints the array
 * after each time two elements are swapped.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for quick_sort
 *
 * @array: The array to be sorted
 * @low: The low index of the partition to be sorted
 * @high: The high index of the partition to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
	/* Find partition index and sort the partitions */
	partition_index = lomuto_partition(array, low, high, size);

	/* Recursively sort the subarrays */
	quick_sort_recursive(array, low, partition_index - 1, size);
	quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for quick_sort
 *
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in the array
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
	if (array[j] < pivot)
	{
	i++;
	/* Swap array[i] and array[j] */
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;

	/* Print the array after each swap */
	print_array(array, size);
	}
	}

	/* Swap array[i + 1] and array[high] (pivot) */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	/* Print the array after each swap */
	print_array(array, size);

	return (i + 1);
}

