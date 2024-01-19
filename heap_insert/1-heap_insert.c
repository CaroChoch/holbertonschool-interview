#include "binary_trees.h"


/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: Root of the tree
 * Return: The size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (size + 1);
}

/**
 * find_parent - Find the parent for the first empty place
 *
 * @root: Root of the tree
 * @i: Index of the parent wanted
 * @size: Size of the tree
 * Return: The node with the place
 */

heap_t *find_parent(heap_t *root, size_t index, size_t size)
{
	heap_t *left, *right;

	if (index == size)
		return (root);
	if (index > size)
		return (NULL);

	left = find_parent(root->left, 2 * index + 1, size);
	right = find_parent(root->right, 2 * index + 2, size);

	if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 *
 * @root: Root of the tree
 * @value: Value to insert
 * Return: The new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent, *tmp;
    size_t tree_size;
    int temp_value;

    if (root == NULL)
        return (NULL);
    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);
    if ((*root) == NULL)
    {
        *root = new_node;
        return (new_node);
    }
    tree_size = binary_tree_size(*root);
    parent = find_parent(*root, 0, (tree_size - 1) / 2);
    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;

    tmp = new_node;
    while (tmp->parent && tmp->n > tmp->parent->n)
    {
        temp_value = tmp->n;
        tmp->n = tmp->parent->n;
        tmp->parent->n = temp_value;
        tmp = tmp->parent;
    }

    return (tmp);
}
