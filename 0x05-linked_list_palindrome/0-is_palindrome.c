#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: list of numbers
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	int numbers[10240], i, j;

	if (*head)
	{
		for (i = 0; temp; i++)
		{
			numbers[i] = temp->n;
			temp = temp->next;
		}
		for (j = 0; j < i; j++)
		{
			if (numbers[j] != numbers[i - j - 1])
				return (0);
		}
	}
	return (1);
}
