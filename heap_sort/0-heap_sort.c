#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int lenght_array = size; /* store the length of the array */

	/* Check if the array is not NULL and size is not 0 */
    if (array != NULL && size != 0)
	{
        /* Build heap (rearrange array) */
		for (i = size / 2 - 1; i >= 0; i--)
			heapify(array, size, i, lenght_array);

        
		for (i = size - 1; i >= 0; i--)
		{
            /* Move current root to end */
			int temp = array[0];
			array[0] = array[i];
			array[i] = temp;
            /* print current array state */
			print_array(array, lenght_array);
            /* call max heapify on the reduced heap */
			heapify(array, i, 0, lenght_array);
		}
	}
}

/**
 * heapify - Heapify a subtree with root node i
 * @array: array to sort
 * @size: size of heap
 * @i: root node
 * @lenght_array: lenght of the initial array
 * Return: no return
 */
void heapify(int *array, int size, int i, int lenght_array)
{
	int largest = i;
	int left = 2 * i + 1; /* left child */
	int right = 2 * i + 2; /* right child */

    /* If left child is larger than root */
	if (left < size && array[left] > array[largest])
		largest = left;

    /* If right child is larger than largest so far */
	if (right < size && array[right] > array[largest])
		largest = right;

    /* If largest is not root */
	if (largest != i)
	{
        /* Swap the largest with the root */
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
        /* print current array state */
		print_array(array, lenght_array);
        /* Recursively heapify the affected sub-tree */
		heapify(array, size, largest, lenght_array);
	}
}
