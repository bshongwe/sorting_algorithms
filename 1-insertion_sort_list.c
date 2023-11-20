#include "sort.h"

/**
 * insertion_sort_list - Func uses insertion sort algorithm
 * 			 to sort doubly-linked list.
 * @list: Doubly-linked list head pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - Func swaps n1 and n2 in doubly-linked
 * list
 * @hd: Doubly linked head pointer
 * @n1: First node pointer
 * @n2: Second node pointer
 * Return: void
 */
void swap_nodes(listint_t **hd, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = n2;
	}
	else
	{
		*hd = n2;
	}

	(*n1)->prev = n2;
	*n1 = n2->prev;
}
