#include "search.h"


/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list)
		return NULL;

	skiplist_t *node = list, *express = list->express, *last = node;

	while (express != NULL && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		node = express;
		express = express->express;
	}

	if (express != NULL)
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);

    else
	{
		last = node;
		while (last->next != NULL)
			last = last->next;
	}

	if (express != NULL)
		printf("Value found between indexes [%lu] and [%lu]\n", node->index, express->index);

    else
		printf("Value found between indexes [%lu] and [%lu]\n", node->index, last->index);

    while (node != NULL && node->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		node = node->next;
	}
	if (node != NULL && node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		return node;
	}
	return NULL;
}
