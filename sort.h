#ifndef _SORT_H_
#define _SORT_H_

/* LIBRARIES */
#include <stdlib.h>
#include <stdio.h>

/* MACROS DIRECTION */
#define UP 0
#define DOWN 1

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

/* Boolean struct */

/**
 * enum bool - Boolean values enumeration
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/* print prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Additionals */
void swap_nodes(listint_t **hd, listint_t **n1, listint_t *n2);
void swap_integers(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
int get_max(int *array, int size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);

/* Tasks */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif /*end of _SORT_H_ file */
