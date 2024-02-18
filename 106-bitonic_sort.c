/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * swap_ints: -  this swaps two ints in an arr
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
 * bitonic_merge - this sort a bitonic seq inside an arr of ints
 * @array: arr of ints
 * @size: size of the arr
 * @start: starting index of the seq in arr to sort
 * @seq: size of the seq to sort
 * @flow:direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - this converts an arr of ints into a bitonic seq
