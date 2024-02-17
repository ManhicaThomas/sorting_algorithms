#include <stdio.h>
#include "sort.h"

/**
 * print_list - this prints a list of ints
 * @list: list to be printed
 */
void print_list(const listint_t *list)
{
	int y;
	while (list)
	{
		if (y > 0)
			printf(", ");
		printf("%d", list->n);
		++y;
		list = list->next;
	}
	printf("\n");
}
