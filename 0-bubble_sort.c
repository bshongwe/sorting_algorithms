#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Function uses bubble sort algorithm
 * to sort array of ints
 * @array: Input int array
 * @size: Array size
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, z;

	if (!array || !size)
	{
		return;
	}

	/* Loop counter */
	i = 0;
	/* Outer loop */
	while (i < size)
	{
		/* Inner loop */
		for (z = 0; z < size - 1; z++)
		{
			/* Comparing elements */
			if (array[z] > array[z + 1])
			{
				tmp = array[z];
				array[z] = array[z + 1];
				array[z + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
