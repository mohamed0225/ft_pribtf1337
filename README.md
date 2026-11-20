*This project has been created as part of the 42 curriculum by mohaidbe.*

# ft_printf

## Description

The **ft_printf** project is part of the 42 School curriculum. The goal of this project is to recreate the behavior of the standard C library function `printf()`.

The project introduces variadic functions in C and provides a deeper understanding of how formatted output works.

The function handles different format specifiers and converts various data types into formatted output.

### Supported Conversions

- `%c` – Prints a single character.
- `%s` – Prints a string.
- `%p` – Prints a pointer address in hexadecimal format.
- `%d` – Prints a decimal integer.
- `%i` – Prints an integer.
- `%u` – Prints an unsigned decimal integer.
- `%x` – Prints a number in lowercase hexadecimal format.
- `%X` – Prints a number in uppercase hexadecimal format.
- `%%` – Prints a percent sign.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This generates the `libftprintf.a` static library.

### Available Makefile Rules

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

### Usage

Include the header file in your C source file:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c libftprintf.a -o program
```

Run the executable:

```bash
./program
```

## Resources

### Documentation and References

- [printf(3) – Linux Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h – C Variadic Arguments](https://en.cppreference.com/w/c/variadic.html)
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)
- [C Programming Language Reference](https://en.cppreference.com/w/c.html)

### AI Usage

AI tools were used as learning and development assistants during this project.

They helped with:
- Understanding variadic functions (`va_list`, `va_start`, `va_arg`,  and `va_end`).
- Understanding the behavior of the standard `printf()` function.
- Clarifying format specifiers and edge cases.
- Identifying potential bugs and understanding unexpected test results.
- Improving test cases and debugging strategies.

All implementation decisions, code, debugging, and final testing were reviewed and handled by the student.

## Algorithm and Data Structure

### Algorithm

The implementation uses a sequential parsing algorithm.

1. Initialize the variadic argument list using `va_start`.
2. Iterate through the format string character by character.
3. When a normal character is encountered, print it directly.
4. When a `%` character is encountered, check the following character to identify the conversion specifier.
5. Retrieve the corresponding argument using `va_arg`.
6. Convert and print the argument according to its format specifier.
7. Count the number of characters printed.
8. Finish by calling `va_end` and return the total number of characters printed.

### Data Structure

The project mainly uses the `va_list` data type to handle a variable number of arguments.

A `va_list` allows the function to access arguments passed after the format string without knowing their number in advance.

The implementation also uses integer variables to track the current position in the format string and the total number of characters printed.

### Algorithm Justification

A sequential parsing algorithm is suitable for this project because the format string must be processed from left to right, preserving the order of the output.

It provides a simple and efficient way to identify conversion specifiers and process their corresponding arguments.

The algorithm has a time complexity of **O(n)**, where `n` is the length of the format string, excluding the additional cost of printing and converting the arguments.
