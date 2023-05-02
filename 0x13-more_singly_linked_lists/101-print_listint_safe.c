#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);


/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t count = 0;

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		current = head;
		head = head->next;
		if (current <= head)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			exit(98);
		}
	}

	return (count);
}
