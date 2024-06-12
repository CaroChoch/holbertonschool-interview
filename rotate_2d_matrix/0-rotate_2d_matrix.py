#!/usr/bin/python3
""" Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """
    Gives a rotate 90 degrees of a 2D matrix
    Arguments:
        - matrix: List of n integers
    """
    if not matrix or not matrix[0]:
        return

    # Transpose the matrix
    n = len(matrix)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse the matrix
    for i in range(n):
        matrix[i].reverse()
