#include "sort.h"

/**
 * selection_sort - implementing selection sort algorithm
 * @array: the array to sort
 * @size: the array size
 * Return: void - nothing
 */
void selection_sort(int *array, size_t size)
{
	int pos, holder, temp;
	size_t i, n;

	n = 0;
	pos = -1;
	while (array && n < size)
	{
		holder = array[n];
		for (i = n + 1; i < size; i++)
		{
			if (holder > array[i])
			{
				pos = i;
				holder = array[i];
			}
		}

		if (pos == -1)
		{
			++n;
			continue;
		}

		temp = array[pos];
		array[pos] = array[n];
		array[n] = temp;
		++n;
		pos = -1;
		print_array(array, size);
	}
}
