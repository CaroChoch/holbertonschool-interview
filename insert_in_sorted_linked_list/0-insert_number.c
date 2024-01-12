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

    if (head == NULL)
    	return (NULL);

    new = malloc(sizeof(listint_t));

    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    current = *head;

    if (current == NULL || current->n > number)
    {
        new->next = current;
        *head = new;
        return (new);
    }

    while (current->next != NULL)
    {
        if (current->next->n > number)
            break;
        current = current->next;
    }

    new->next = current->next;
    current->next = new;

    return (new);
}
