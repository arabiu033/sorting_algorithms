#include "sort.h"

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array to sort
 * @size: the array size
 * Return: void - nothing
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}

void sort(int *array, int l, int h, size_t size)
{
	int partition;

	if (l < h)
	{
		partition = partition_array(array, l, h, size);
		sort(array, l, partition - 1, size);
		sort(array, partition + 1, h, size);
	}
}

int partition_array(int *array, int l, int h, size_t size)
{
	int pivot, pivot_index, partition_high, partition_low, temp, i, j, signal;

	pivot = array[h];
	pivot_index = h;
	partition_high = h - 1;
	partition_low = l;
	signal = 1;
	for (i = partition_low; i <= partition_high; i++)
	{
		if (array[i] > pivot)
		{
			for (j = partition_high; j > i; j--)
			{
				if (array[j] < pivot)
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					print_array(array, size);
					signal = 0;
					partition_high = j + 1;
					break;
				}
			}

			if (signal)
			{
				array[pivot_index] = array[i];
				array[i] = pivot;
				print_array(array, size);
				return (i);
			}
		}

		if (i == partition_high)
		{
			if (array[i] > pivot)
			{
				array[pivot_index] = array[i];
				array[i] = pivot;
				print_array(array, size);
			}
			return i;
		}
	}

	return (-1);
}
