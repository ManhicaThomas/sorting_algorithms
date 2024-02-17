#include "sort.h"

/**
 * swap_ints - this swaps two int in an arr.
 * @a: first int to swap.
 * @b: second int to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - this sorts an arr of int in ascending order
 * @array: arr of int to sort
 * @size: size of the arr
 * Description: this prints the arr after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				prints_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
