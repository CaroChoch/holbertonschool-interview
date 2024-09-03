#include "substring.h"

/**
 * find_substring - finds all the possible substrings containing a list of words
 * @s: the string to scan
 * @words: the array of words all substrings must be a concatenation arrangement of
 * @nb_words: the number of elements in the array words
 * @n: holds the address at which to store the number of elements in the returned array
 * Return: an array storing each index in s at which a substring was found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int len, word_len, i, *indices, *count;

    if (!s || !words || !n || nb_words == 0)
        return NULL;

    len = strlen(s);
    word_len = strlen(words[0]);
    indices = init_indices(len);
    if (!indices)
        return NULL;

    count = init_count(nb_words);
    if (!count)
    {
        free(indices);
        return NULL;
    }

    for (i = *n = 0; i <= len - nb_words * word_len; i++)
    {
        int match = check_words(s, words, i, nb_words, word_len, count);
        *n = add_index_if_match(indices, n, i, match);
    }

    free(count);
    return indices;
}

int *init_indices(int len)
{
    return malloc(len * sizeof(int));
}

int *init_count(int nb_words)
{
    return calloc(nb_words, sizeof(int));
}

int check_words(const char *s, const char **words, int i, int nb_words, int word_len, int *count)
{
    int j, k;

    memset(count, 0, nb_words * sizeof(int));
    for (j = 0; j < nb_words; j++)
    {
        for (k = 0; k < nb_words; k++)
        {
            if (!count[k] && strncmp(s + i + j * word_len, words[k], word_len) == 0)
            {
                count[k] = 1;
                break;
            }
        }
        if (k == nb_words) // No matching word found
            return 0;
    }
    return 1;
}

int add_index_if_match(int *indices, int *n, int i, int match)
{
    if (match)
    {
        indices[*n] = i;
        return *n + 1;
    }
    return *n;
}
