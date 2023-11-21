#include <stdio.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: This function initiates the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, size);
}

/**
 * merge_sort_recursive - Recursive func to implement the top-down merge sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: This function recursively divides the array into subarrays
 * until the base case (size < 2) is reached. Then, it merges the subarrays
 * back together using the merge function.
 */
void merge_sort_recursive(int *array, size_t size)
{
	size_t mid;
	size_t left_size;
	size_t right_size;
	int *left;
	int *right;

	if (size < 2)
		return;

	mid = size / 2;
	left_size = mid;
	right_size = size - mid;
	left = array;
	right = array + mid;
	merge_sort_recursive(left, left_size);
	merge_sort_recursive(right, right_size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	merge(array, size, left, left_size, right, right_size);

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - Merges two subarrays into one sorted array
 * @array: The array containing both subarrays
 * @size: The size of the array
 * @lft: The left subarray
 * @l_s: The size of the left subarray
 * @rht: The right subarray
 * @r_s: The size of the right subarray
 *
 * Description: This function merges two subarrays into one sorted array.
 */
void merge(int *array, size_t size, int *lft, size_t l_s, int *rht, size_t r_s)
{
	size_t i = 0, j = 0, k = 0;
	int *merged = malloc(sizeof(int) * size);

	if (merged == NULL)
		return;

	while (i < l_s && j < r_s)
	{
		if (lft[i] <= rht[j])
		{
			merged[k] = lft[i];
			i++;
		}
		else
		{
			merged[k] = rht[j];
			j++;
		}
		k++;
	}

	while (i < l_s)
	{
		merged[k] = lft[i];
		i++;
		k++;
	}

	while (j < r_s)
	{
		merged[k] = rht[j];
		j++;
		k++;
	}

	for (k = 0; k < size; k++)
		array[k] = merged[k];

	free(merged);
}
