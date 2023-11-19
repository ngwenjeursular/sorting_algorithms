#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element to swap.
 * @b: Pointer to the second element to swap.
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions an array around a pivot element.
 * @array: The array to partition.
 * @low: index of the first element in the partition.
 * @high: index of the last element in the partition.
 *
 * Return: index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);

	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int low, high, pivotIndex;

	if (size <= 1)
	{
		return;
	}

	low = 0;
	high = size - 1;

	pivotIndex = partition(array, low, high, size);

	quick_sort(array, pivotIndex);
	quick_sort(array + pivotIndex + 1, size - pivotIndex - 1);
}
