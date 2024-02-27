#include "palindrome.h"

/**
 * is_palindrome - Checks if a given unsigned integer is a palindrome or not
 * @n: The unsigned integer to be checked.
 *
 * Return: If the integer is a palindrome - 1.
 *         Otherwise - 0
 */
int is_palindrome(unsigned long n)
{
    int reversed = 0, remainder, original;
    original = n;

    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if (original == reversed)
        return (1);
    else
        return (0);
}