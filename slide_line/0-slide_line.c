#include "slide_line.h"

/**
 * merge_and_slide - Slides and merges an array in the specified direction.
 * @line: Points to an array of integers containing size elements.
 * @size: Number of elements in @line.
 * @direction: Indicates the direction to slide and merge.
 */
void merge_and_slide(int *line, size_t size, int direction)
{
    size_t i, j;

    if (direction == SLIDE_LEFT)
    {
        j = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0) {
                if (j > 0 && line[j - 1] == line[i])
                {
                    line[j - 1] *= 2;
                    line[i] = 0;
                } else {
                    if (j != i)
                    {
                        line[j] = line[i];
                        line[i] = 0;
                    }
                    j++;
                }
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        j = size - 1;
        for (i = size - 1; i < size; i--)
        {
            if (line[i] != 0) {
                if (j < size - 1 && line[j + 1] == line[i])
                {
                    line[j + 1] *= 2;
                    line[i] = 0;
                } else
                {
                    if (j != i)
                    {
                        line[j] = line[i];
                        line[i] = 0;
                    }
                    j--;
                }
            }
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Points to an array of integers containing size elements.
 * @size: Number of elements in @line.
 * @direction: Left or right.
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    merge_and_slide(line, size, direction);
    return 1;
}
