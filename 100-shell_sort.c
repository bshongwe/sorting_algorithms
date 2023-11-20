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
 * shell_sort - Sort an array of integers using Knuth
 *              interval sequence.
 * @array: Input integers array.
 * @size: Array size.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, j, k;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			k = j;
			while (k >= gap && array[k - gap] > array[k])
			{
				swap_integers(array + k, array + (k - gap));
				k -= gap;
			}
		}
		print_array(array, size);
	}
}
