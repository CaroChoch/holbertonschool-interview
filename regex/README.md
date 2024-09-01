# RegEx
## 📝 Description

This project consists of creating a function capable of checking whether a given pattern corresponds to a specific string using regular expressions. The function must handle the special characters `.` and `*`, where `.` corresponds to any unique character, and `*` corresponds to zero or more of the previous character. This project is particularly useful for understanding and implementing fundamental concepts of regular expressions in C.

The function developed must be robust, capable of handling empty strings and patterns, and return a precise match according to the specified rules. This project is part of a series of exercises to strengthen skills in the preparation of technical interviews, focusing on algorithms and data structures.

## 📚 Resources

- [Regex Tutorial - Learn Regular Expressions](https://www.regular-expressions.info/tutorial.html)
- [Regular Expressions - Wikipedia](https://en.wikipedia.org/wiki/Regular_expression)

## 🛠️ Technologies and Tools Used

- **C Language**: Programming language used to implement regular expression management functions, chosen for its performance and common use in embedded systems.

- **GCC Compiler**: Used to compile C code with strict options to ensure the robustness of the code (`-Wall -Werror -Wextra -pedantic`).

- **Betty Style**: Set of code style rules used to ensure that the code is clean, readable and compliant with industry standards.

## 📋 Prerequisite

- ![Ubuntu 14.04](https://img.shields.io/badge/Ubuntu-14.04_LTS-orange)
- ![GCC 4.8.4](https://img.shields.io/badge/gcc-4.8.4-blue)
- ![Betty](https://img.shields.io/badge/Betty-Style-green)

## 📊 Data Files

Here are the code and data contained in the files used for this project:

<details>
<summary>main.c</summary>
<br>

```c
#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

#define TEST_MATCH(s, p)    do {\
    {\
        int res = regex_match(s, p);\
        printf("%s -> %s = %d\n", s, p, res);\
    }\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    TEST_MATCH("H", "H");
    TEST_MATCH("HH", "H");
    TEST_MATCH("HH", "H*");
    TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");
    TEST_MATCH("Holberton", ".*");
    TEST_MATCH("Alex", ".*");
    TEST_MATCH("Guillaume", ".*");
    TEST_MATCH("Julien", ".*");
    TEST_MATCH("Holberton", "Z*H.*");
    TEST_MATCH("Holberton", "Z*H.*olberton");
    TEST_MATCH("Holberton", "Z*H.*o.");
    TEST_MATCH("Holberton", "Z*H.*o");
    TEST_MATCH("Holberton", "holberton");
    TEST_MATCH("Holberton", ".olberton");
    TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

    return (EXIT_SUCCESS);
}
```
</details>

## 🚀 Installation and Configuration

Follow these steps to install and configure the project on your system:

1. **Cloning the deposit**:

```bash
git clone https://github.com/CaroChoch/holbertonschool-interview.git
   cd holbertonschool-interview/regex
```

2. **Compilation**:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c
```

3. **Execution**:

```bash
./a.out
```

## 💡 Use

Here are concrete example of using the project:

**Command Line**:

```bash
./a.out
```

**Output**:

```bash
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
```

## ✨ Main Features

1. **Exact Match:** The program can check if a string corresponds exactly to a given pattern.

2. **Special Character Support:** The program supports special characters. and * for flexible matches.

3. **Management Of Empty Chains:** The function can manage empty chains and empty patterns in a robust way.

4. **Performance:** Implemented in C, the program is designed to be efficient and effective, even with long chains.

## 📝 List of Tasks

Here is the list of tasks listed for this project:

| Number | Task | Description |
| ------ | -------------------------------- | --------------------------------------------------------------------------- |
| 0 | [Simple RegEx](https://github.com/CaroChoch/holbertonschool-interview/blob/main/regex/regex.c) | Write a function that checks if a given pattern corresponds to a specific string using regular expressions. |

