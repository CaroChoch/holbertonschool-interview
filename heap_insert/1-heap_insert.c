#include "binary_trees.h"


/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *tmp = NULL;
	int tmp_value = 0;

	if (!root)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	tmp = *root;
	while (tmp->left && tmp->right)
	{
		if (tmp->left->left == NULL || tmp->left->right == NULL)
			tmp = tmp->left;
		else if (tmp->right->left == NULL || tmp->right->right == NULL)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if (!tmp->left)
		tmp->left = new_node;
	else
		tmp->right = new_node;
	new_node->parent = tmp;
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		tmp_value = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp_value;
		new_node = new_node->parent;
	}
	return (new_node);
}
