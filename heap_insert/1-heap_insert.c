#include "binary_trees.h"


/**
 * create_heap_node - Creates a new heap node with the given value
 * @value: The value to be stored in the node
 * Return: A pointer to the newly created node
 */
heap_t *create_heap_node(int value)
{
    return binary_tree_node(NULL, value);
}

/**
 * find_insertion_point - Finds the insertion point for a new node in the heap
 * @root: A pointer to the root node of the heap
 * Return: A pointer to the insertion point in the heap
 */
heap_t *find_insertion_point(heap_t *root)
{
    while (root->left != NULL && root->right != NULL)
    {
        if (root->left->left == NULL || root->left->right == NULL)
            root = root->left;
        else if (root->right->left == NULL || root->right->right == NULL)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

/**
 * swap_nodes - Swaps the values of two heap nodes
 * @node1: A pointer to the first node
 * @node2: A pointer to the second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
    int temp_value = node1->n;
    node1->n = node2->n;
    node2->n = temp_value;
}

/**
 * heapify_up - Performs the heapify-up operation to maintain the max heap property
 * @new_node: A pointer to the newly inserted node
 */
void heapify_up(heap_t *new_node)
{
    while (new_node->parent != NULL && new_node->n > new_node->parent->n)
    {
        swap_nodes(new_node, new_node->parent);
        new_node = new_node->parent;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = NULL;
    heap_t *insertion_point = NULL;

    if (root == NULL)
        return NULL;

    new_node = create_heap_node(value);

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    insertion_point = find_insertion_point(*root);

    if (insertion_point->left == NULL)
        insertion_point->left = new_node;
    else
        insertion_point->right = new_node;

    new_node->parent = insertion_point;

    heapify_up(new_node);

    return new_node;
}
