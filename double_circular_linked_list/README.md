# Double Circular Linked List

## 📝 Description

The `Double Circular Linked List` project consists of the creation and management of a circular doubly chained list. This type of data structure makes it possible to navigate in both directions (front and backward) and loop in a circular way, which is particularly useful for applications requiring effective data manipulation.

Key features of the project include adding nodes at the end and beginning of the list, as well as managing the memory allocated for these nodes. Functions must be compiled using strict standards to ensure the quality and performance of the code. This project implements advanced concepts of data structures, while respecting precise code style rules.

## 📚 Resources

- [Linked Lists in C](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
- [C Standard Library](https://www.cplusplus.com/reference/clibrary/)

## 🛠️ Technologies and Tools Used

- **C**: Main programming language used for its performance and low-level control.
- **GCC**: Compiler used to compile C code with specific flags to ensure the conformity and robustness of the code.
- **Betty**: A linter to ensure that the code meets the specified style and documentation standards.

## 📋 Prerequisite

- ![ Ubuntu](https://img.shields.io/badge/Ubuntu-14.04_LTS-orange)
- ![ GCC](https://img.shields.io/badge/gcc-4.8.4-brightgreen)
- ![ Betty](https://img.shields.io/badge/betty-style-blue)

## 📊 Data Files

<details>
<summary>list.h</summary>
<br>

```c
#ifndef LIST_H
#define LIST_H

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
  char *str;
  struct List *prev;
  struct List *next;
} List;

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
```
</details>
<details>
<summary>0-main.c</summary>
<br>

```c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list)
{
    List *tmp;

    tmp = list;
    while (tmp)
    {
        printf("%s\n", tmp->str);
        printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
        printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
        tmp = tmp->next;
        if (tmp == list)
            break;
    }
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    List *list;

    list = NULL;
    add_node_end(&list, "Holberton");
    add_node_end(&list, "School");
    add_node_end(&list, "Full");
    add_node_end(&list, "Stack");
    add_node_end(&list, "Engineer");

    printf("Added to the end:\n");
    print_list(list);
    list = NULL;
    add_node_begin(&list, "Holberton");
    add_node_begin(&list, "School");
    add_node_begin(&list, "Full");
    add_node_begin(&list, "Stack");
    add_node_begin(&list, "Engineer");

    printf("Added to the beginning:\n");
    print_list(list);
    return (0);
}
```
</details>

## 🚀 Installation and Configuration

1. **Clone the GitHub repository:**

```sh
git clone https://github.com/CaroChoch/holbertonschool-interview.git
```

2. **Navigate to the directory containing the project:**

```sh
cd double_circular_linked_list
```

3. **Compile the C files:**

```sh
gcc -Wall -Wextra -Werror -pedantic 0-add_node.c -o add_node
```

4. **Run the executable:**

```sh
./add_node
```

## 💡 Use

- **Example of use**:

```sh
./add_node
```

- **Output**:

```sh
Added to the end:
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
```

## ✨ Main Features

- **Add Node at the End**: Add a new node at the end of the list.
- **Add Node at the Beginning**: Add a new node at the beginning of the list.
- **Memory Management**: Manage the memory allocated for the nodes.

## 📝 List of Tasks

| Number | Task | Description |
| ------ | ----------------------- | ------------------------------------------------------------------------------- |
| 0 | [Add Nodes](https://github.com/CaroChoch/holbertonschool-interview/blob/main/double_circular_linked_list/0-add_node.c) | Create functions to add nodes at the beginning and end of the double circular chain list. |
