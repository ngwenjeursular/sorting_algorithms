#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max_value;
	int *count_array, *sorted_array;

	if (array == NULL || size < 2)
		return;

	max_value = array[0];
	for (i = 1; i < size; i++)
		if ((size_t) array[i] > max_value)
			max_value = (size_t)array[i];

	count_array = malloc(sizeof(int) * (max_value + 1));
	if (!count_array)
		return;

	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;
	for (i = 1; i <= max_value; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max_value + 1);
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(count_array);
	free(sorted_array);
}
