#include "sort.h"

/**
 * bubble_sort - Function uses bubble sort algorithm
 * to sort array of ints
 * @array: Input int array
 * @size: Array size
 */
void bubble_sort(int *array, size_t size);
{
	int tmp;
	size_t i, z;

	if (!array || !size)
	{
		return;
	}

	i = 0;
	while (i < size)
	{
		for (z = 0; z < size - 1; z++)
		{
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
