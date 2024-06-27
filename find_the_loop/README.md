# <p align='center'>🌟 Find the Loop 🌟</p>

## 📝 Description

**Find the Loop** is a project that focuses on the detection of loops in C-chained lists. The main objective is to provide an effective implementation that makes it possible to locate cycles in a data structure, especially chained lists. This project is essential for developers working on data management algorithms, because loop detection is a fundamental operation in optimizing data paths.

The key features of this project include a function that detects the presence of loops in a chained list and returns the address of the node where the loop begins. This project is developed with strict coding standards and uses style tools to ensure the quality and maintainability of the code.

## 📚 Resources

- [Betty Style Guide](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
- [Static Library for Testing](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/interviews/472/libloop.a)
- [Understanding Linked Lists](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Detecting Loop in Linked List](https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/)

## 🛠️ Technologies and Tools Used

- **C**: The project is entirely developed in C, a low-level programming language that provides precise control over the memory and resources of the system, which is crucial for the manipulation of data structures such as chained lists.
- **GCC**: The GNU Compiler Collection (GCC) compiler is used to compile the code. It is chosen for its compatibility and compliance with C standards, as well as for its advanced compilation and debugging features.
- **Betty**: A code style linter used to ensure that the code follows the strict style conventions of the project. It helps to maintain the readability and quality of the code.

## 📋 Prerequisite

- ![C](https://img.shields.io/badge/C-90-blue)
- ![GCC](https://img.shields.io/badge/gcc-4.8.4-brightgreen)
- ![Ubuntu](https://img.shields.io/badge/ubuntu-14.04_LTS-orange)

## 📊 Data Files

[libloop.a](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/interviews/472/libloop.a)

<details>
<summary>lists.h</summary>
<br>

```c
#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

#endif
```

</details>
<details>
<summary>0-main.c</summary>
<br>

```c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    listint_t *head2;
    listint_t *node;

    head2 = NULL;
    add_nodeint(&head2, 0);
    add_nodeint(&head2, 1);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 3);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 98);
    add_nodeint(&head2, 402);
    add_nodeint(&head2, 1024);
    print_listint_safe(head2);
    node = find_listint_loop(head2);
    if (node != NULL)
    {
        printf("Loop starts at [%p] %d\n", (void *)node, node->n);
    }
    free_listint_safe(&head2);
    head = NULL;
    node = add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 5);
    add_nodeint(&head, 6);
    node->next = add_nodeint(&head, 7);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint_safe(head);
    node = find_listint_loop(head);
    if (node != NULL)
    {
        printf("Loop starts at [%p] %d\n", (void *)node, node->n);
    }
    free_listint_safe(&head);
    return (0);
}
```

</details>
<details>
<summary>lib.c</summary>
<br>

```c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * struct listdone_s - singly linked list
 * @node: node
 * @next: points to the next node
 *
 * Description: singly linked list node done structure
 * for Holberton project
 */
typedef struct listdone_s
{
	const struct listint_s *node;
	struct listdone_s *next;
} listdone_t;


/**
 * _find_in_list - Search for a node in a list
 *
 * @done: The list of known nodes
 * @node: The address of the node being searched
 *
 * Return: The address of the node if it was found. NULL otherwise
 */
const listint_t *_find_in_list(listdone_t **done, const listint_t *node)
{
	listdone_t *p;

	p = *done;
	while (p)
	{
		if (p->node == node)
		{
			return (p->node);
		}
		p = p->next;
	}
	p = malloc(sizeof(listdone_t));
	if (p == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	p->node = node;
	p->next = *done;
	*done = p;
	return (NULL);
}

/**
 * _free_done - Free a list
 *
 * @done: A pointer to the first element of a list
 */
void _free_done(listdone_t *done)
{
	listdone_t *tmp;

	while (done)
	{
		tmp = done->next;
		free(done);
		done = tmp;
	}
}

/**
 * add_nodeint - Add a node at the beginning of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * free_listint_safe - Free a list that can contain a loop
 *
 * @h: A pointer to the first element of a list
 *
 * Return: The number of element in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listdone_t *done;
	listint_t *head;
	listint_t *tmp;
	size_t n;

	head = *h;
	n = 0;
	done = NULL;
	while (head)
	{
		if (_find_in_list(&done, head) != NULL)
		{
			_free_done(done);
			*h = NULL;
			return (n);
		}
		tmp = head;
		head = head->next;
		free(tmp);
		n++;
	}
	_free_done(done);
	*h = NULL;
	return (n);
}

/**
 * print_listint_safe - Prints a list thaht can contains a loop
 *
 * @head: A pointer to the first element of a list
 *
 * Return: The number of element printed
 */
size_t print_listint_safe(const listint_t *head)
{
	listdone_t *done;
	size_t n;

	n = 0;
	done = NULL;
	while (head)
	{
		if (_find_in_list(&done, head) != NULL)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			_free_done(done);
			return (n);
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		n++;
	}
	_free_done(done);
	return (n);
}
```

</details>

## 🚀 Installation and Configuration

1. **Step 1: Clone the deposit**

```sh
git clone https://github.com/CaroChoch/holbertonschool-interview.git
```

2. **Step 2: Navigate to the directory**

```sh
cd holbertonschool-interview/find_the_loop
```

3. **Step 3: Compile the code**

```sh
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main
```

4. **Step 4: Run the program**

```sh
./main
```

## 💡 Use

### Example of use:

```sh
./main
```

#### Result:

```c
[0x206410f0] 1024
[0x206410d0] 402
[0x206410b0] 98
[0x20641090] 4
[0x20641070] 3
[0x20641050] 2
[0x20641030] 1
[0x20641010] 0
[0x20641560] 1024
[0x20641540] 402
[0x20641010] 98
[0x20641030] 7
[0x20641050] 6
[0x20641070] 5
[0x20641090] 4
[0x206410b0] 3
[0x206410d0] 2
[0x206410f0] 1
[0x20641110] 0
-> [0x20641030] 7
Loop starts at [0x20641030] 7
```

## ✨ Main Features

1. **Loop detection in a chained list**: The find_listint_loop function allows you to detect the presence of a loop in a chained list. It returns the address of the node where the loop begins, or NULL if there is no loop

2. **Security and memory management**: The project follows strict memory management standards, avoiding the use of standard library functions such as malloc and free.

3. **Compliance with style conventions**: Use the Betty tool to ensure that the code complies with coding style conventions, thus improving the readability and maintainability of the code.

## 📝 List of Tasks

| Number | Task | Description |
| ------ | ----------------------- | ------------------------------------------------------------------------------- |
| 0 | [Find the loop](https://github.com/CaroChoch/holbertonschool-interview/tree/main/find_the_loop) | Write a function that finds the loop in a chained list. |

## 📬 Contact

- LinkedIn Profile: [Caroline Chochoy](https://www.linkedin.com/in/caroline-chochoy62/)