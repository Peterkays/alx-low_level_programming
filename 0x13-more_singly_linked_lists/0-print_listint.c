#include "lists.h"
#include <stdio.h>

/**
  * print_listint - Print the linked list.
  * @h: Linked list.
  * Return: Number of nodes.
  */

size_t print_listint(const listint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
