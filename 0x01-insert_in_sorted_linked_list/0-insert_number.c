#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: the address of the new node, or NULL if it failed
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

	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}

	while (current)
	{
		if (current->n < number)
		{
			if (!current->next || current->next->n > number)
			{
				new->next = current->next;
				current->next = new;
				break;
			}
		}
		current = current->next;
	}
	return (new);
}
