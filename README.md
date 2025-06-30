# HOLBERTON SCHOOL - _PRINTF

First group project.

---

![portada](https://github.com/user-attachments/assets/ce0e3689-88df-4eae-a59b-8636195a6bc2)



# 🖨️ `_printf` Project in C

Custom implementation of the `printf` function from the C standard library.  
Supports multiple basic format specifiers using variadic functions (`stdarg.h`).

---

## 📚 Supported Specifiers

| Specifier | Description            |
|-----------|------------------------|
| `%c`      | Prints a character     |
| `%s`      | Prints a string        |
| `%d`, `%i`| Prints an integer      |
| `%%`      | Prints the `%` symbol  |

---

## 🧠 Project Objective

This project aims to:

- Understand the use of functions with variable arguments.
- Apply structures and format control.
- Emulate the internal behavior of `printf`.
- Strengthen modularization and error control in C.

---

## ⚙️ Compilation

To compile the project, use:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

> 📌 This command compiles all `.c` files in the directory and generates an executable named `a.out`.

---

## 🧪 Usage Example

File: `main.c`

```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Return value: _printf = %d | printf = %d\n", len, len2);

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printf("Return value: _printf = %d | printf = %d\n", len, len2);

    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);

    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    return (0);
}
```

---

## 🗺️ `_printf` Flow Diagram

![flow_printffff](https://github.com/user-attachments/assets/c1cbbce1-89bb-43da-8a9f-6913c68787b5)


---

## 📁 Project Structure

```
_printf/
├── main.c         # Main test file
├── printf.c       # _printf logic
├── print_int.c    # Helper function for integers
├── main.h         # Header file
└── README.md      # Project documentation
```

---

## 📌 Future Improvements

- [ ] Add `%u`, `%o`, `%x`, `%X`
- [ ] Support for `%p` (pointers)
- [ ] Flags (`+`, ` `, `0`, etc.)
- [ ] Precision and minimum width

---

## 👩‍💻 Authors

**Selena Gomez Rueda** 
Developed as an academic project for **Holberton School**.

---

## 🔗 Useful Resources

- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`stdarg.h`](https://en.cppreference.com/w/c/variadic)

---

⭐ If this project helped you, feel free to leave a star!
