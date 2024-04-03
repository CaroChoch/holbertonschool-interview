#!/usr/bin/python3
"""N queens problem"""
import sys


def is_safe(board, row, col, n):
    """
    Check if a queen can be placed on board[row][col]
    Arguments:
    - board: list of the positions of the queens
    - row: row to check
    - col: column to check
    - n: number of queens
    Return:
    - True if the position is safe
    """
    # Check each column before the current column
    for c in range(col):
        # If there's already a queen in the same row or diagonal, it's not safe
        if board[c] == row or abs(board[c] - row) == abs(c - col):
            return False
    # If there are no conflicts, it's safe to place the queen
    return True


def solve(board, col, n):
    """
    Solve the N queens problem
    Arguments:
    - board: list of the positions of the queens
    - col: current column
    - n: number of queens
    Return:
    - Print the board with the queens' positions
    """
    # If all queens are placed, print the solution
    if col == n:
        print(str([[c, board[c]] for c in range(n)]))
        return
    # Try placing the queen in each row of the current column
    for row in range(n):
        if is_safe(board, row, col, n):
            board[col] = row
            # Recur to place queens in the remaining columns
            solve(board, col + 1, n)


def main():
    """
    Main function
    """
    # Check if the correct number of arguments is provided
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        # Get N from command-line arguments
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    # Ensure N is at least 4 for the problem to be solvable
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    # Initialize the board with all queens in the first column
    board = [0 for i in range(n)]
    # Start solving the problem from the first column
    solve(board, 0, n)


if __name__ == "__main__":
    main()
