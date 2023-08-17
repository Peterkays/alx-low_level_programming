#include "lists.h"

/**
 * get_dnodeint_at_index - Get a node with a index in the list.
 * @head: Head of the list.
 * @index: Index of the node.
 * Return: Node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	current = head;
	if (head == NULL)
		return (NULL);

	for (i = 0; i < index && current != NULL; i++, current = current->next)
	{
		;
	}
	if (current == NULL)
		return (NULL);
	else
		return (current);
}
