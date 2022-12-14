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
	if (array)
		sort(array, 0, size - 1, size);
}

/**
 * sort - recursive calls to each partition generated
 * @array: working array
 * @l: lowest index
 * @h: highest index
 * @size: array size
 * Return: void - nothing
 */
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

/**
 * partition_array - Return the index location of new partition
 * @array: working array
 * @l: lowest index
 * @h: highest index
 * @size: aray size
 * Return: new partition location
 */
int partition_array(int *array, int l, int h, size_t size)
{
	int pivot, pivot_index, partition_high, partition_low, i, j, signal;

	pivot = array[h];
	pivot_index = h;
	partition_high = h;
	partition_low = l;
	for (i = partition_low; i <= partition_high; i++)
	{
		signal = 1;
		if (array[i] > pivot)
		{
			for (j = partition_high - 1; j > i; j--)
			{
				if (array[j] < pivot)
				{
					swap(array, i, j, size);
					signal = 0;
					partition_high = j;
					break;
				}
			}

			if (signal)
			{
				swap(array, i, pivot_index, size);
				return (i);
			}
		}

		if (i == partition_high)
		{
			if (array[i] > pivot)
				swap(array, i, pivot_index, size);
			return (i);
		}
	}

	return (-1);
}

/**
 * swap - swaps two array index
 * @array: the array to work on
 * @i: first index
 * @j: second index
 * @size: array size
 * Return: void - nothing
 */
void swap(int *array, int i, int j, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}
