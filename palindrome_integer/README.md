# Palindrome integer

## General:

- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
- All files should end with a new line
- Code should use the Betty style.
- It's not allowed to use global variables
- No more than 5 functions per file
- The prototypes of all functions should be included in the header file called `palindrome.h`


## Task:

### Palindrome unsigned integer:

Write a function that checks whether or not a given unsigned integer is a palindrome.

- Prototype: `int is_palindrome(unsigned long n);`
- Where `n` is the number to be checked
- Function must return `1` if `n` is a palindrome, and `0` otherwise
- It's not allowed to allocate memory dynamically (malloc, calloc, …)