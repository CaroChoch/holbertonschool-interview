#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	/* Temporary array to store sorted output */
    int *output;
	/* Maximum number in the array */
    int max;
	/* Current digit's place value */
	int exp;
	/* Index */
    size_t i;
	/* Index */
	int j;

	/* If array is NULL or size is less than 1 */
    if (!array || size < 2)
        return;

	/* Allocate memory for output array */
    output = malloc(sizeof(*output) * size);
    if (!output)
        return; /* malloc failed */

	/* Find the maximum number in the array */
    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

	/* Perform counting sort for every digit */
	/* exp is the current digit's place value : 1, 10, 100, 1000, ... */
    for (exp = 1; max / exp > 0; exp *= 10)
    {
		/* Array to store the count of each digit (0 to 9) */
        int count[10] = {0};

		/* Count occurrences of each digit in the current place value */
        for (i = 0; i < size; i++)
            count[(array[i] / exp) % 10]++;

		/* Change count[i] so that count[i] now contains actual */
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

		/* Build the output array using the counts positions */
        for (j = size - 1; j >= 0; j--)
		{
			output[count[(array[j] / exp) % 10] - 1] = array[j];
			count[(array[j] / exp) % 10]--;
		}
		/* Copy the sorted elements from output back to the original array */
        for (i = 0; i < size; i++)
            array[i] = output[i];

		/* Print the array after each pass */
        print_array(array, size);
    }

	/* Free the allocated memory for the output array */
    free(output);
}
