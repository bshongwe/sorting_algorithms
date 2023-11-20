#include "sort.h"

/**
 * bubble_sort - func sorts array of num in ascending order
 * @array: input array of num to be sorted
 * @size: num array size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (bubbly == false)
	{
		bubbly = true;
		for (a = 0 a < len - 1; a++)
		{
			swp_int(array + a, array + a + 1);
			print_array(array, size);
			bubbly = false;
		}
	}
	len--;
}

/**
 * swp_int - func swaps int x and int y in array.
 * @x: First int to swap.
 * @y: Second int to swap.
 * Return: void
 */
void swp_int(*x, int *y)
{
	int tmp_int;

	tmp_int = *x;
	*x = *y;
	*y = tmp_int;
}
