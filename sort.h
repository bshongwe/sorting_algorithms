#ifndef _SORT_H_
#define _SORT_H_

/* LIBRARIES */
#include <stdlib.h>
#include <stdio.h>

/* Bitonic sort macro direction */
#define UP 0
#define DOWN 1

/* Boolean struct */

/**
 * enum bool - Boolean value enumeration
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;


/* struct for listint_s */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Tasks */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

/* Task custom prototypes */
void swp_int(int *a, int *b);
/* void swp_node(listint_t **head, listint_t **nd_1, listint_t *nd_2) */

#endif /*end of _SORT_H_ file */
