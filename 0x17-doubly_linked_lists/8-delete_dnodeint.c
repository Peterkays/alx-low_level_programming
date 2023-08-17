#include "lists.h"

/**
 * delete_dnodeint_at_index - Insert a node in a index of the list.
 * @head: Head of the list.
 * @index: Index.
 * Return: 1 if works, -1 if doesn't.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	current = *head;
	if (index == 0)
	{
		if (current->next != NULL)
		{ (current->next)->prev = NULL;
			*head = current->next;
			free(current);
			return (1);
		}
		else
		{ *head = NULL;
			free(current);
			return (1);
		}
	}
	for (i = 0; i < index && current != NULL; i++, current = current->next)
	{
		;
	}
	if (i <= index && current != NULL)
	{
		if (current->next == NULL)
		{ (current->prev)->next = NULL;
			free(current);
			return (1);
		}
		else
		{ (current->prev)->next = current->next;
			(current->next)->prev = current->prev;
			free(current);
			return (1);
		}
	}
	else
		return (-1);
}
