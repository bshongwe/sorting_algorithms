#include "sort.h"

/**
 * insertion_sort_list - func sorts doubly-linked int list
 * 			and prints list after each swap
 * @list: list head pointer
 * Return: void
 */
void insertion_sort_list(listint_t **list);
{
	listint_t *r, *t, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (r = (*list)->next; r != NULL; r = temp)
	{
		temp = r->next;
		t = r->prev;
		while (t != NULL && r->nd < t->nd)
		{
			swp_node(list, &t, r);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swp_node - func swaps listint_t doubly-linked list nodes
 * @head: doubly-linked list head pointer
 * @nd1: first input node
 * @nd2: second input node
 * Return: void
 */
void swp_node(listint_t **head, listint_t **nd_1, listint_t *nd_2)
{
	(*nd_1)->next = nd_2->next;
	if (nd_2->next != NULL)
		nd_2->next->prev = *nd_1;
	nd_2->prev = (*nd_1)->prev;
	nd_2->next = *nd_1;
	if ((*nd_1)->prev != NULL)
	{
		(*nd_1)->prev->next = nd_2;
	}
	else
		*head = nd_2;
	(*nd_1)->prev = nd_2;
	*nd_1 = nd_2->prev;
}
