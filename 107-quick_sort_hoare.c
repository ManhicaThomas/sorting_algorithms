#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - order a subset of an arr of ints
 * according to the hoare partition scheme
 * @array: arr of ints
 * @size: size of the arr
 * @left: starting index of the subset to order
 * @right: ending index of the subset order
 * Return: final partition index
 *
 * Description: this uses the last element of the partition as the pivot
 * prints the arr after each of two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - this implements the quicksort algorithm through recursion
 * @array: arr of ints to sort
 * @size: size of the arr 
 * @left: starting index of the arr partition to order
 * @right: starting index of the partition to order
 *
 * Description: this uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

