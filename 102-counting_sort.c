#include "sort.h"

/**
 * get_max - Func gets maximum value in integers array.
 * @array: Integers input array.
 * @size: Array size.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, j;

	for (max = array[0], j= 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		return;
	}
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (max + 1); j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(count);
}
