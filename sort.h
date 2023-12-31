#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/*data structures*/

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

#include <stdbool.h>
#include <stddef.h>

/*prototypes*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void swap_list(listint_t **ptr1, listint_t **ptr2, int n);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);

/*Quick sort*/
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);

void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/*Cocktail shaker sort*/
/*void swap_nodes(listint_t **list, listint_t *a, listint_t *b);*/
void cocktail_sort_list(listint_t **list);
listint_t *swap_nodes(listint_t *node, listint_t **head);

/*merge sort*/
/*void merge(int *array, int *left, size_t mid, int *right, size_t size);*/
void merge(int *array, size_t size, int *lft, size_t l_s, int *rht, size_t r_s);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif
