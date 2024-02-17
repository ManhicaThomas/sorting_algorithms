#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - this prints an arr of int
 * @array: the arr to be printed
 * @size: num of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t z;

	z = 0;
	while (array && z < size)
	{
		if (z > 0)
			printf(", ");
		printf("%d", array[z]);
		++z;
	}
	printf("\n");
}
