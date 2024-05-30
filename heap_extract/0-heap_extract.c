#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 *
 * @root: double pointer to the root node of the heap
 *
 * Return: the value stored in the root node, 0 on failure
 */
int heap_extract(heap_t **root)
{
    int n, size;
    heap_t *node, **array;

    if (!root || !*root)
        return (0);
    node = *root;
    n = node->n;
    size = _height(node) + 1;
    array = malloc(sizeof(heap_t *) * size);
    if (!array)
        return (0);
    array[0] = node;
    for (n = 1; n < size; n++)
    {
        if (array[(n - 1) / 2]->left == array[n - 1])
            array[n] = array[(n - 1) / 2]->right;
        else
        {
            if (array[(n - 1) / 2]->right)
                array[n] = array[(n - 1) / 2]->right;
            else
                array[n] = array[(n - 1) / 2]->left;
        }
    }
    node = array[n - 1];
    if (array[n - 1]->parent)
    {
        if (array[n - 1]->parent->left == array[n - 1])
            array[n - 1]->parent->left = NULL;
        else
            array[n - 1]->parent->right = NULL;
    }
    else
        *root = NULL;
    free(array);
    return (n);
}
