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
 * hoare_partition - Func uses hoare partition scheme to order
 *                    a subset of an array of integers.
 * @array: Input array of integers.
 * @size: Size of array.
 * @left: Starting index of subset to order.
 * @right: Ending index of subset to order.
 *
 * Return: Final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_integers(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Func uses quicksort algorithm recursively.
 * @array: Input array of integers.
 * @size: Size of array.
 * @left: Starting index of array partition.
 * @right: Ending index of array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Func sorts array of integers in ascending
 *                    order using Hoare partition.
 * @array: Input array of integers.
 * @size: Size of array.
 *
 * Description: Prints array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	hoare_sort(array, size, 0, size - 1);
}
