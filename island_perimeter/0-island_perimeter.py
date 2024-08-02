#!/usr/bin/python3
""" Returns the perimeter of the island described in grid """


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid """

    perimeter = 0  # Initialize perimeter counter

    # Loop through each row in the grid
    for row in range(len(grid)):

        # Loop through each column in the row
        for col in range(len(grid[row])):
            # Check if the current cell is land
            if grid[row][col] == 1:
                # Add 4 to the perimeter for each land cell
                perimeter += 4
                # Check the cell above
                if row > 0 and grid[row - 1][col] == 1:
                    # Subtract 2 if the cell above is also land
                    perimeter -= 2
                # Check the cell to the left
                if col > 0 and grid[row][col - 1] == 1:
                    # Subtract 2 if the cell to the left is also land
                    perimeter -= 2

    # Return the total perimeter
    return perimeter
