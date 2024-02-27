#include "palindrome.h"

/**
 * is_palindrome - Checks if a given unsigned integer is a palindrome or not
 * @n: The unsigned integer to be checked.
 *
 * Return: If the integer is a palindrome - 1.
 *         Otherwise - 0.
 */

int is_palindrome(unsigned long n)
{
    char str[100]; /* Define a character array to store the number */
    int length = 0;

    /* Convert the number to a string manually */
    while (n > 0) {
        str[length++] = n % 10 + '0';
        n /= 10;
    }
    str[length] = '\0'; /* Terminate the string with a null character */

    /* Check if the string is a palindrome */
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; /* If characters do not match, it's not a palindrome */
        }
    }
    return 1; /* If all characters match, it's a palindrome */
}
