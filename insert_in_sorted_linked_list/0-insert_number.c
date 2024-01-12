#include "lists.h"

/**
 * add_node - Adds a number to a sorted linked list.
 *            of a list_t list.
 * @head: A pointer to the head of the list_t list.
 * @number: The number to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
    listint_t *current;

	current = *head;

    new = malloc(sizeof(listint_t));

    if (new == NULL)
        return (NULL);

    new->n = number;

    while (current != NULL && current->next != NULL && number > current->next->n )
		current = current->next;
    
    if ((current->n > number) || (current == NULL))
	{
        new->next = *head;
		*head = new;
	}
	else
	{
		new->next = current->next;
		current->next = new;
	}

    return (new);
}
