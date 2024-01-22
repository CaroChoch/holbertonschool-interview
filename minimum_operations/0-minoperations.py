#!/usr/bin/python3
"""
Method that calculates the fewest number of operations needed to result in exactly
n H characters in the file.
"""


def minOperations(n):
    """
    Method that calculates the fewest number of operations needed
    to result in exactly n H characters in the file.
    Argument:
        n: integer
    Return:
        integer
    """
    if n <= 1:
        return 0
    else:
        for i in range(2, n + 1):
            if n % i == 0:
                return minOperations(int(n / i)) + i
        return n
