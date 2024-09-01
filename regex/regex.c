#include "regex.h"


/**
 * regex_match - compares two strings
 * @str: string to scan
 * @pattern: regular expression
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int regex_match(char const *str, char const *pattern)
{
    if (*str == '\0' && *pattern == '\0')
        return (1);
	if (*pattern == '\0')
		return (0);

    if (*str == *pattern)
        return (regex_match(str + 1, pattern + 1));

    if (*pattern == '.')
    {
        if (*(pattern + 1) == '*')
            return (regex_match(str, pattern + 2));
        if (regex_match(str + 1, pattern + 1))
            return (1);
        return (regex_match(str + 1, pattern));
    }

    if (*pattern == '*')
    {
        if (*(pattern + 1) == '*')
            return (regex_match(str, pattern + 1));
        if (regex_match(str, pattern + 1))
            return (1);
        return (regex_match(str + 1, pattern));
    }
    return (0);
}
