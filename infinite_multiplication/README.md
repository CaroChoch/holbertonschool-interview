# 🌟 Infinite Multiplication 🌟

## 📝 Description 
The Infinite Multiplication project aims to develop a program capable of multiplying two positive numbers with potentially infinite length. This project showcases the ability to handle large integers and perform precise calculations, overcoming the limitations of standard data types in C programming. 

The primary function of this program is to take two positive numbers as input, multiply them, and print the result. It includes rigorous error handling to ensure that inputs are valid and adheres to strict coding standards, ensuring reliability and robustness.

## 📚 Resources
- [C Programming Language Documentation](https://en.cppreference.com/w/c)
- [GCC Compiler Documentation](https://gcc.gnu.org/onlinedocs/)
- [Ubuntu 14.04 LTS Documentation](https://wiki.ubuntu.com/TrustyTahr/ReleaseNotes)
- [Betty Coding Style](https://github.com/hs-hq/Betty)
- [Man Page for bc](https://man7.org/linux/man-pages/man1/bc.1.html)
- [_putchar.c](https://github.com/hs-hq/_putchar.c/blob/master/_putchar.c)

## 🛠️ Technologies and Tools Used
- **C Programming Language**: Used for implementing the core logic of the program. Chosen for its efficiency and control over system resources.
- **GCC Compiler**: Utilized to compile the C code with specific flags to ensure code quality and error checking.
- **Ubuntu 14.04 LTS**: The target environment for running and testing the program. Ensures compatibility and stability.
- **Betty Coding Style**: Enforced coding standards to maintain code readability and consistency.

## 📋 Prerequisites
- **GCC Compiler**: ![GCC](https://img.shields.io/badge/gcc-4.8.4-blue)
- **Ubuntu**: ![Ubuntu](https://img.shields.io/badge/Ubuntu-14.04%20LTS-orange)
- **Betty Linter**: ![Betty](https://img.shields.io/badge/betty-linter-green)

## 🚀 Installation and Configuration

1. **Clone the repository**: Since there is no GitHub repository at the moment, create a new one and clone it to your local machine.
    ```sh
    git clone https://github.com/your-username/infinite_multiplication.git
    cd infinite_multiplication
    ```

2. **Ensure GCC and required tools are installed**:
    ```sh
    sudo apt-get update
    sudo apt-get install build-essential
    sudo apt-get install gcc
    ```

3. **Compile the program**:
    ```sh
    gcc -Wall -Werror -Wextra -pedantic 0-mul.c _putchar.c -o mul
    ```

4. **Run the program**:
    ```sh
    ./mul num1 num2
    ```
    Replace `num1` and `num2` with the two numbers you want to multiply.

## 💡 Usage
- **Example 1**:
    ```sh
    ./mul 123 456
    ```
    This will output `56088`.

- **Example 2**:
    ```sh
    ./mul 999 999
    ```
    This will output `998001`.

## ✨ Main Functionalities
1. **Multiplication of Large Numbers**: The primary functionality of this program is to multiply two positive numbers of potentially infinite length.
2. **Error Handling**: The program checks for invalid input and ensures that the inputs are valid numbers, providing appropriate error messages.
3. **Memory Management**: Efficient memory allocation and deallocation to handle large numbers without causing memory leaks.

## 📝 List of Tasks

| Number | Task | Description |
| ------ | ---- | ----------- |
| 0 | **[Infinite Multiplication](https://intranet.hbtn.io/projects/2276#)** | Write a program that multiplies two positive numbers. Ensure correct usage and input validation. If inputs are invalid, print an error message and exit with status 98. |

## 📬 Contact
- LinkedIn Profile: [Caroline CHOCHOY](https://www.linkedin.com/in/caroline-chochoy62/)
