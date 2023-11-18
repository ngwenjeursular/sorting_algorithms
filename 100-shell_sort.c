#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order using Shell sort
* with the Knuth sequence
* @array: The array to be sorted
* @size: The size of the array
* Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = tmp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}

