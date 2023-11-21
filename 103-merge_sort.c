#include "sort.h"
#include <stdbool.h>

/**
 * merge_subarr - Func sorts integers subarray.
 * @subarr: Subarray of integers array to sort.
 * @buff: Buffer to store sorted subarray.
 * @front: Front index of array.
 * @mid: Middle index of array.
 * @back: Back index of array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t j, k, l = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (j = front, k = mid; j < mid && k < back; l++)
	{
		buff[l] = (subarr[j] < subarr[k]) ? subarr[j++] : subarr[k++];
	}
	for (; j < mid; k++)
	{
		buff[l++] = subarr[j];
	}
	for (; k < back; k++)
	{
		buff[l++] = subarr[k];
	}
	for (j = front, l = 0; j < back; j++)
	{
		subarr[j] = buff[l++];
	}

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Func implements merge sort algorithm through recursion.
 * @subarr: Integers subarray to sort.
 * @buff: Buffer to store result.
 * @front: Front index of subarray.
 * @back: Back index of subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Func sorts intgers array of integers in ascending
 *              order using top-down merge sort algorithm.
 * @array: Integers array.
 * @size: Array Size.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
	{
		return;
	}

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
	{
		return;
	}

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
