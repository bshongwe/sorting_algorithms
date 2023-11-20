#include "sort.h"

/**
 * swap_integers - Func swaps two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Func sorts array of integers using
 * selection sort algorithm and prints array after each
 * swap.
 * @array: Input array of integers.
 * @size: Size of integers array.
 *
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, z;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (z = j + 1; z < size; z++)
			min = (array[z] < *min) ? (array + z) : min;

		if ((array + j) != min)
		{
			swap_integers(array + j, min);
			print_array(array, size);
		}
	}
}
