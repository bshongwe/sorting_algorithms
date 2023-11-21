#include "sort.h"

/**
 * bubble_sort - Function uses bubble sort algorithm
 * to sort array of ints
 * @array: Input int array
 * @size: Array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (!array || !size)
	{
		return;
	}

	i = 0;
	do {
		swapped = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap directly without temporary variable */
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = true;
			}
		}

		/* Adaptive swap mechanism: skip swaps if already sorted */
		if (!swapped)
		{
			break;
		}

		i++;
	} while (swapped);
}
