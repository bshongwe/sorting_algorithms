#include "sort.h"

/**
 * selection_sort - func uses selection sort algorithm to
 *                  sort array of integers in ascending order
 * @array: input int array
 * @size: array size
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t index, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (index = 0; index < size - 1; index++)
	{
		min = array + index;
		for (j = index + 1; j < size; j++)
		{
			min = (array[j] < *min) ? (array + j) : min;
		}

		if ((array + index) != min)
		{
			swp_num(array + index, min);
			print_array(array, size);
		}
	}
}

/**
 * swp_num - func swaps a and b in the array
 * @a: first input int
 * @b: second input int
 * Return: void
 */
void swp_num(int *a, int *b)
{
	int temp_num;

	temp_num = *a;
	*a = *b;
	*b = temp_num;
}
