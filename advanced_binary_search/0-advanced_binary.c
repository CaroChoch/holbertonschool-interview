#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int mid, index = -1;

	if (array == NULL)
		return (-1);
	printf("Searching in array: ");

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
		printf(", ");
	}
	printf("\n");

	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (size == 1)
			return (mid);
		if (array[mid - 1] < value)
    		return (mid);
    }
	if (size == 1)
		return (-1);
	if (array[mid] < value)
	{
		index = advanced_binary(array + mid + 1, size - mid - 1, value);
		if (index != -1)
			return (mid + 1 + index);
	}
	else
	{
		index = advanced_binary(array, mid + 1, value);
		return (index);
	}
	return (index);
}
