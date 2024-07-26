# Radix Sort

## 📝 Description

The **Radix Sort** project is an implementation of the Radix sorting algorithm, designed to sort integer arrays in ascending order. This algorithm is particularly effective for tables containing positive numbers. It works by sorting the numbers digits by digits, starting with the least significant digit (Least Significant Digit - LSD).

The proposed implementation is distinguished by its efficiency and compliance with good programming practices. It is designed to be compiled on Ubuntu 14.04 LTS with GCC 4.8.4 and respects the Betty coding style. The project also highlights features such as dynamic memory use to optimize performance and ensure the flexibility of the algorithm.

## 📚 Resources

- [Radix Sort Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)

## 🛠️ Technologies and Tools Used

- `GCC`: Used to compile programs with -Wall, -Werror, -Wextra, and -pedantic flags to ensure high-quality and error-free code.
- `Ubuntu`: Operating system on which the project is developed and tested.
- `Betty Style`: Code style tool used to ensure that the code meets coding style standards.
- `Emacs/Vim/Vi`: Recommended text editors for writing and editing the source code.

## 📋 Prerequisite

- ![ GCC](https://img.shields.io/badge/gcc-4.8.4-green)
- ![ Ubuntu](https://img.shields.io/badge/Ubuntu-14.04_LTS-orange)
- ![ Betty](https://img.shields.io/badge/Betty-Style-blue)

## 📊 Data Files
<details>
<summary>print_array.c</summary>
<br>

```c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```
</details>
<details>
<summary>0-main.c</summary>
<br>

```c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**

main - Entry point

Return: Always 0
*/
int main(void)
{
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

print_array(array, n);
printf("\n");
radix_sort(array, n);
printf("\n");
print_array(array, n);
return (0);
}
```
</details>

## 🚀 Installation and Configuration

1. **Step 1:** Clone the GitHub repository

```sh
git clone https://github.com/MathieuMorel62/holbertonschool-interview.git
```

2. **Step 2:** Navigate to the project's directory

```sh
cd radix_sort
```

3. **Step 3:** Compile the C files in this way

```sh
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

4. **Step 4:** Run the compiled program

```sh
./radix
```

## 💡 Use

- **Example of use 1:** Sorting a table of integers

```sh
./radix
```

This will run the program and display the sorted array after each significant iteration of the Radix tria.

Result:

```sh
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## ✨ Main Features

1. **Tri Radix LSD**: Implements the Radix sorting algorithm using the least significant digit, optimized for positive numbers.

2. **Dynamic memory management**: Uses malloc and free to dynamically manage the memory needed for sorting.

3. **Printing the intermediate steps**: Displays the table at each significant step of the sorting process for a better understanding of the algorithm's progress.

## 📝 Liste des Tâches

| Nombre | Tache | Description |
| ------ | ----- | ----------- |
| 0 | [Radix sort](https://github.com/CaroChoch/holbertonschool-interview/blob/main/radix_sort/0-radix_sort.c) | Function to sort an array of integers in ascending order using the Radix sort algorithm. |
