#!/usr/bin/python3
""" Rain """


def rain(walls):
    """
    Calculate how much water will be retained after it rains
    Arguments:
        - walls: list of non-negative integers
    Returns:
        - integer indicating total amount of rainwater retained
    """
    # If the list is empty, return 0
    if not walls:
        return 0

    # INITIALIZATION OF VARIABLES
    # number of walls
    n = len(walls)
    # left[i] contains the height of the tallest wall to the left of i
    left = [0] * n
    # right[i] contains the height of the tallest wall to the right of i
    right = [0] * n
    # total amount of rainwater retained
    water = 0

    # Fill left array
    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    # Fill right array
    right[n - 1] = walls[n - 1]
    for i in reversed(range(n - 1)):
        right[i] = max(right[i + 1], walls[i])

    # Calculate the amount of water retained
    for i in range(n):
        water += min(left[i], right[i]) - walls[i]

    return water
