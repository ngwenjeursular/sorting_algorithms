#include "sort.h"

/**
 * swap_list - swaps the elements of the list
 * @ptr1: first pointer
 * @ptr2: second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 * Return: void
 */
void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *current, *tmp;

	current = *ptr1;
	tmp = *ptr2;

	current->next = tmp->next;
	tmp->prev = current->prev;

	if (current->next)
		tmp->next->prev = current;

	if (current->prev)
		current->prev->next = tmp;

	current->prev = tmp;
	tmp->next = current;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = current;
}

/**
 * increase_sort - move the bigger numbers to the end
 * @ptr: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 * Return: void
 */
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *current;

	current = *ptr;

	while (current != *limit && current->next != *limit)
	{
		if (current->n > current->next->n)
		{
			swap_list(&current, &(current->next), 0);
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}

	*limit = current;
	*ptr = current;
}

/**
 * decrease_sort - moves the smaller numbers to the start
 *
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *current;

	current = *ptr;

	while (current != *limit && current->prev != *limit)
	{
		if (current->n < current->prev->n)
		{
			swap_list(&(current->prev), &current, 1);
			if (current->prev->prev == NULL)
				*list = current->prev;
			print_list(*list);
		}
		current = current->prev;
	}

	*limit = current;
	*ptr = current;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order using the
 * Cocktail shaker sort algorithm
 *
 * @list: head of the linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		increase_sort(&ptr, &limit1, list);
		decrease_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
