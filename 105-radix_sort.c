#include "sort.h"

/**
 * get_max - Func gets maximum value in array of integers.
 * @array: Input array of integers.
 * @size: Size of array.
 *
 * Return: Maximum integer in array.
 */
int get_max_int(int *array, int size)
{
	int max_int, i;

	for (max_int = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_int)
		{
			max_int = array[i];
		}
	}

	return (max_int);
}

/**
 * radix_count_sort - Func uses counting sort algorithm to sort significant
 *                        digits of array of integers in ascending order.
 * @array: Input array of integers.
 * @size: Size of the array.
 * @sig: Significant digit to sort on.
 * @buff: Buffer to store sorted array.
 */
void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / sig) % 10] += 1;
	}

	for (i = 0; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = buff[i];
	}
}

/**
 * radix_sort - Func uses radix sort algorithm to sort
 *              array of integers in ascending order.
 * @array: Input array of integers.
 * @size: Size of array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max_int, sig, *buff;

	if (array == NULL || size < 2)
	{
		return;
	}

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
	{
		return;
	}

	max_int = get_max_int(array, size);
	for (sig = 1; max_int / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
