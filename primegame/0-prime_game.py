#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """
    Determines the winner of the game
    Arguments:
        - x: number of rounds
        - nums: array of n integers
    Returns:
        - name of the player that won the most rounds
    """

    # Check if the number of rounds is correct
    if x != len(nums):
        return None

    # Sort the list of numbers
    nums.sort()

    # Check if the maximum number is less than 2
    #if nums[-1] < 2:
        #return None

    # Create a list of prime numbers
    primes = [False, False] + [True for i in range(nums[-1] - 1)]
    for i in range(2, int(nums[-1] ** 0.5) + 1):
        if primes[i]:
            for j in range(i ** 2, nums[-1] + 1, i):
                primes[j] = False

    # Count the number of prime numbers
    primes_count = [0]
    for i in range(1, len(primes)):
        primes_count.append(primes_count[i - 1] + primes[i])

    # Determine the winner
    winner = 0
    for n in nums:
        winner += primes_count[n] % 2 == 1

    # if the winner cannot be determined return None
    if winner * 2 == x:
        return None
    # Return the name of the player that won the most rounds
    elif winner * 2 > x:
        return "Maria"
    else:
        return "Ben"
