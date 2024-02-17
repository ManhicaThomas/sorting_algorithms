#include "sort.h"

/**
 * swap_ints - this swaps two ints in an arr
 * @a: first int to swap
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
 * selection_sort - this sort an arr of ints in ascending order
 * using the selection sort algorithm
 * @array: arr of ints
 * @size: size of the arr
 * Description: this prints the arr after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t t, m;

	if (array == NULL || size < 2)
		return;

	for (t = 0; t < size - 1; t++)
	{
		min = array + t;
		for (m = t + 1; m < size; t++)
			min = (array[m] < *min) ? (array + m) : min;

		if ((array + t) != min)
		{
			swap_ints(array + t, min);
			print_array(array, size);
		}
	}
}
