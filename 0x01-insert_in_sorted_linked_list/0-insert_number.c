#include "lists.h"
#include <stdlib.h>

/**
 * 
 *
 *
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
    listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
    if (new == NULL)
	{
        return (NULL);
	}

	while (current->next)
	{
		if (current->next->n > number)
		{
			new->n = number;
			new->next = current->next;
			current->next = new;
			break;
		}
		else {
			current = current->next;
		}
	}
	while (current->next)
	{
		current = current->next;
	}
	return (new);
}
