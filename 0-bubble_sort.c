#include "sort.h"

/**
 * bubble_sort - func sorts array of num in ascending order
 * @array: input array of num to be sorted
 * @size: num array size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (bubbly == false)
	{
		bubbly = true;
		for (index = 0; index < len - 1; index++)
		{
			if (array[index] > array[index +1])
			{
				swp_num(array + index, array + index + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
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
