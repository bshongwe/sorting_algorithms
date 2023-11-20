#include "sort.h"

/**
 * swap_integers - Func swaps a and b in an array.
 * @a: First integer.
 * @b: Second integer.
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Func orders integers array subset using Lomuto
 *                    partition scheme.
 * @array: Integers input array
 * @size: Array size.
 * @left: Starting index of subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: Final partition index (Success).
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_integers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_integers(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Func implements quicksort algorithm by recursion.
 * @array: Input array of integers.
 * @size: Size of array.
 * @left: Starting index of array partition to order.
 * @right: Ending index of array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Func sorts array of integers using Lomuto
 *              order and quicksort algorithm.
 * @array: Input integers array.
 * @size: Array size.
 *
 * Description: Prints array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	lomuto_sort(array, size, 0, size - 1);
}
