#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i;
    int mid, index = -1;

    /* Check if the array is valid */
    if (array == NULL)
        return (-1);

    /* Print the current array state */
    printf("Searching in array: ");

    /* Print each element of the array */
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    /* Calculate the middle index */
    mid = (size - 1) / 2;

    /* If the middle element is the target value */
    if (array[mid] == value)
    {
        /* If the size of the array is 1, return the middle index */
        if (size == 1)
            return (mid);
        /**
         * If the element before the middle is less than the target value
         * Return the middle index
         */
        if (array[mid - 1] < value)
            return (mid);
    }
    /**
     * If the size of the array is 1, and the target value is not found
     *return -1
     */
    if (size == 1)
        return (-1);

    /**
     * If the middle element is less than the target value
     * search the right half
     */
    if (array[mid] < value)
    {
        /* Recursively search the right half of the array */
        index = advanced_binary(array + mid + 1, size - mid - 1, value);
        /* If the target value is found in the right half, return the index */
        if (index != -1)
            return (mid + 1 + index);
    }
    /**
     * If the middle element is greater than or equal to the target value
     * search the left half
     */
    else
    {
        index = advanced_binary(array, mid + 1, value);
        /* If the target value is found in the left half, return the index */
        return (index);
    }
    /* Return the final index */
    return (index);
}
