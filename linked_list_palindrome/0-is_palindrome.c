#include "lists.h"

/**
 * reverse - reverses a linked list
 * @head: pointer to head of list
 * Return: pointer to head of reversed list
 */
listint_t *reverse(listint_t *head)
{
    listint_t *prev = NULL, *current = head, *nextNode = NULL;
    
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half, *prev_slow = *head;

    /* Move 'fast' and 'slow' pointers to find the middle of the linked list */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    /* Check if the linked list is empty or has only one element (considered a palindrome) */
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    /* If the length is odd, move 'slow' to the next node */
    if (fast != NULL)
        slow = slow->next;

    /* If the length is odd, move 'slow' to the next node */
    second_half = slow;
    prev_slow->next = NULL;
    second_half = reverse(second_half);

    /* Compare the first and second halves of the linked list */
    while (*head != NULL && second_half != NULL)
    {
        if ((*head)->n == second_half->n)
        {
            /* Move to the next nodes if the values match */
            *head = (*head)->next;
            second_half = second_half->next;
        }
        else
            /* if it's not a palindrome */
            return (0);
    }

    /* Check if both halves have reached the end (linked list is a palindrome) */
    if (*head == NULL && second_half == NULL)
        return (1);

    return (0);
}
