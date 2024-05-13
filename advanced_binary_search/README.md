# Advanced Binary Search

## 📝 Description

The `Advanced Binary Search` project is designed to address a complex variant of traditional binary search, which is often limited by the fact that it does not necessarily return the index of the first occurrence of a value in an array. This project aims to solve this problem by developing a function that can locate the first occurrence of a value in an array of sorted integers.

The function developed in this project, `advanced_binary`, takes as input an array of integers, its size, and the value to be searched for, and returns the index of the first occurrence of this value. It is particularly useful in cases where values can appear several times in the table. The implementation requires a recursive approach and is designed to display the sub-table in which the search continues at each stage, which is crucial for understanding the search process and for debugging. This project highlights not only the skills in algorithms and data structures, but also the ability to optimize searches in contexts where performance is critical.

## 📚 Resources

- [Betty Style Checker](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
- [Betty Doc Checker](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)
- [C Programming Language](https://www.learn-c.org/)
- [Understanding Binary Search Algorithm](https://www.geeksforgeeks.org/binary-search/)
- [Binary Search Algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)

## 🛠️ Technologies and Tools Used

- **C Programming Language**: Programming language chosen for its performance and proximity to the system, essential for implementing effective search algorithms.

- **GCC Compiler**: Used to compile C programs, ensuring that the code meets strict security and efficiency standards thanks to the `-Wall`, `-Werror`, `-Wextra`, and `-pedantic` flags.

- **Betty Style and Doc Checkers**: Tools used to ensure that the code complies with Betty coding conventions, thus facilitating the maintenance and clarity of the code.

## 📋 Prerequisite

To install and run the project, users must have:

- ![Ubuntu](https://img.shields.io/badge/ubuntu-14.04-orange)
- ![GCC](https://img.shields.io/badge/gcc-4.8.4-green)
- ![C](https://img.shields.io/badge/C-90-blue)

## 📊 Data Files

The following files are crucial for the implementation of **Advanced Binary Search**:

<details>
<summary>search_algos.h</summary>
<br>

Contains the prototypes of the functions used in the project, including the prototype of the `advanced_binary` function.

<br>

```c
#ifndef __BINARY_SEARCH__
#define __BINARY_SEARCH__

#include <stdlib.h>
#include <stdio.h>

int print_array(int *array, int left, int right);
int advanced_binary_rec(int *array, int left, int right, int value);
int advanced_binary(int *array, size_t size, int value);


#endif /* __BINARY_SEARCH__ */
```

</details>
<details>

<summary>0-main.c</summary>

<br>

Main file used to test the features of advanced binary search. It contains tests for different values in a specified array.

<br>

```c
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void) {
    int array[] = {0, 1, 2, 5, 5, 6, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}

```

</details>

## 🚀 Installation and Configuration

To set up and execute this project, follow the steps below:

1. **Clone the directory:**

- Open a terminal and type the following command to clone the GitHub directory:

```bash
git clone https://github.com/CaroChoch/holbertonschool-interview/
```

2. **Navigate to the directory:**

- Move to the directory containing the project files:

```bash
cd advanced_binary_search
```

3. **Compile the code:**

- Compile the source files using `gcc` with the appropriate flags:

```bash
gcc -Wall -Wextra -Werror -pedantic *.c -o advanced_binary
```

4. **Run the program:**

- Run the generated binary to test the binary advanced search feature:

```bash
./advanced_binary
```


## 💡 Use

To use the project after installation, you can run the program compiled with different datasets to see how the `advanced_binary` function works with various arrays. Here are some examples:

**Example of use:**

```bash
./Advanced_binary
```

**Results**:

```c
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

This program will display the search results for the values specified in the `0-main.c` file, demonstrating how the function finds the values indices in a sorted array.

## ✨ Main Features

1. **Advanced Binary Search**: Implements an advanced version of binary search that not only finds a value in a sorted array but also returns the index of the first occurrence of this value. This is particularly useful in tables where values can be duplicated.

2. **Dynamic Display**: During the search, the currently examined subtable is displayed, allowing users to follow the process of dividing the table, providing increased visibility and understanding of the algorithm.

3. **Reduced Use of Loops**: Designed to use recursion with a strict limitation on the use of loops, which increases the efficiency and clarity of the code.

## 📝 List of Tasks

| Number | Task | Description |
| ------ | ----------------------- | ------------------------------------------------------------------------------- |
| 0 | [Advanced Binary Search](https://github.com/CaroChoch/holbertonschool-interview/blob/main/advanced_binary_search/0-advanced_binary.c) | Implement an advanced version of binary search that returns the index of the first occurrence of a value in a sorted array. |

## 📬 Contact

- LinkedIn Profile: [Caroline CHOCHOY](https://www.linkedin.com/in/caroline-chochoy62/)