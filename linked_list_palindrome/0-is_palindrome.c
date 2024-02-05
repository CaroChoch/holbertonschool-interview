#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
 
int is_palindrome(listint_t **head)
{
    listint_t *current;
    int i, j, n = 0;
    int *array;

    current = *head;
    while (current != NULL)
    {
        current = current->next;
        n++;
    }
    array = malloc(n * sizeof(int));
    if (array == NULL)
        return (0);
    for (i = 0; i < n; i++)
    {
        array[i] = (*head)->n;
        *head = (*head)->next;
    }
    for (i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        if (array[i] != array[j])
        {
            free (array);
            return (0);
        }
    }
    free (array);
    return (1);
}
