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
 * compAndSwap - A utility function to compare and swap two elements
 * @a: Integer to compare
 * @b: Integer to compare
 * @i: Index of integer a
 * @j: Index of integer b
 * @dir: Direction of sorting
 */
void compAndSwap(int *a, int i, int j, int dir)
{
	if ((a[i] > a[j]) == dir)
		swap(&a[i], &a[j]);
}

/**
 * bitonicMerge - Recursive function to merge two bitonic sequences
 * @a: Array of integers
 * @low: Starting index of sequence to be merged
 * @cnt: Number of elements in sequence to be merged
 * @dir: Direction of sorting
 */
void bitonicMerge(int *a, int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
			compAndSwap(a, i, i + k, dir);
		bitonicMerge(a, low, k, dir);
		bitonicMerge(a, low + k, k, dir);
	}
}

/**
 * bitonicSort - Recursive function to sort a bitonic sequence
 * @a: Array of integers
 * @low: Starting index of sequence to be sorted
 * @cnt: Number of elements in sequence to be sorted
 * @dir: Direction of sorting
 */
void bitonicSort(int *a, int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		bitonicSort(a, low, k, 1);

		bitonicSort(a, low + k, k, 0);

		bitonicMerge(a, low, cnt, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 *                Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;

	bitonicSort(array, 0, size, up);
}
