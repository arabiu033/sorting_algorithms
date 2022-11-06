#include "sort.h"

/**
 * bubble_sort - Implementing bubble sort algorithms on unsorted numbers
 * @array: the aray to sort
 * @size: size of the array
 * Return: void - nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t signal, i;
	int temp;

	signal = 1;
	while (signal && array)
	{
		for (i = 0; i < size; i++)
		{
			if ((i + 1) < size && array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				signal = 0;
				print_array(array, size);
			}
		}

		signal = !signal ? 1 : 0;
	}
}
