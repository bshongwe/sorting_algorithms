#include "sort.h"

/**
 * bubble_sort - func sorts array of num in ascending order
 * @array: input array of num to be sorted
 * @size: num array size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int temp_num;
	size_t a, b;

	if (!array || !size)
	{
		return;
	}

	a = 0;
	while (a < size)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp_num = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp_num;
				print_array(array, size);
			}
		}
		a++;
	}
}
