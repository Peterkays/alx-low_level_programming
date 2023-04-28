#include "lists.h"
#include <stdio.h>

/**
  * print_list - Print the linked list.
  * @h: Linked list.
  * Return: Number of nodes.
  */

size_t print_list(const list_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		if (h->str)
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		else
		{
			printf("[%d] %s\n", 0, "(nil)");
		}
		h = h->next;
		count++;
	}

	return (count);
}
