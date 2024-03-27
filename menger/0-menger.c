#include "menger.h"
/**
* menger - Draws a 2D Menger Sponge
* @level: Level of the Menger Sponge to draw
* Return: void
*/

void menger(int level)
{
	int i, j, size, x, y;
	char c; /* Declare character variable c */

	if (level < 0)
		return;
	size = pow(3, level);

    /* Loop to iterate over each row of the Menger Sponge */
	for (i = 0; i < size; i++)
	{
		/* Loop to iterate over each column of the Menger Sponge */
		for (j = 0; j < size; j++)
		{
			x = i; /* Assign i to x */
			y = j; /* Assign j to y */
			c = '#'; /* Assign # to c */
			/* Loop to determine if the current cell should be empty */
			while (x > 0)
			{
				/* If conditions for empty cell are met, set c to ' ' */
				if (x % 3 == 1 && y % 3 == 1)
					c = ' ';
					x = x / 3; /* Reduce x coordinate */
					y = y / 3; /* Reduce y coordinate */
			}
			/* Print the character */
			printf("%c", c);
		}
		/* Print a new line */
		printf("\n");
	}
}
