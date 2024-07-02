#include <stdio.h>
#include <stdlib.h>

void rec_merge_sort(int *array, int *temp, size_t start, size_t end);
void merge(int *array, int *temp, size_t start, size_t mid, size_t end);
void print_array(const int *array, size_t size);

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    rec_merge_sort(array, temp, 0, size - 1);
    free(temp);
}

/**
 * rec_merge_sort - Recursively sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @temp: A temporary array to store sorted elements
 * @start: The starting index of the array
 * @end: The ending index of the array
 */
void rec_merge_sort(int *array, int *temp, size_t start, size_t end)
{
    size_t mid;

    if (start < end)
    {
        mid = start + (end - start) / 2;
        rec_merge_sort(array, temp, start, mid);
        rec_merge_sort(array, temp, mid + 1, end);
        merge(array, temp, start, mid, end);
    }
}

/**
 * merge - Merges two sorted arrays into one sorted array
 * @array: The array to be sorted
 * @temp: A temporary array to store sorted elements
 * @start: The starting index of the array
 * @mid: The middle index of the array
 * @end: The ending index of the array
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
    size_t i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + start, mid - start + 1);
    printf("[right]: ");
    print_array(array + mid + 1, end - mid);

    for (i = start, j = mid + 1, k = start; k <= end; k++)
    {
        if (i <= mid && (j > end || array[i] <= array[j]))
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
    }

    for (k = start; k <= end; k++)
        array[k] = temp[k];

    printf("[Done]: ");
    print_array(array + start, end - start + 1);
}
