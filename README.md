# 📚 42 Custom C Library (libft + printf + gnl)

A consolidated, custom-built C static library (`libft.a`) that combines the three foundational projects of the 1337 (42 Network) curriculum: **Libft**, **ft_printf**, and **Get Next Line**. 

This repository serves as a unified utility toolkit, designed to be easily cloned and linked into future C projects that forbid the use of standard C libraries.

---

## 🏗️ Library Architecture

This library is divided into three core modules, each self-contained within its respective directory:

### 1. 🧰 Core Libft (`Libft/`)
A recreation of standard C library functions alongside essential data structures.
* **Memory & Strings:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_strlen`, `ft_strjoin`, `ft_split`, `ft_itoa`, etc.
* **Character Checks:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, etc.
* **File Descriptors:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd`, etc.
* **Linked Lists (Bonus):** Full suite of `t_list` operations (`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstmap`, etc.).

### 2. 🖨️ Formatted Output (`Ft_printf/`)
A custom implementation of the `<stdio.h>` `printf` function.
* Handles variadic arguments to format and print strings, characters, integers, and hexadecimals.
* Supported specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.

### 3. 📖 File Reading (`Get_next_line/`)
A robust function designed to read a file descriptor line by line.
* Includes bonus functionality for handling multiple file descriptors simultaneously without losing reading threads.
* Efficient static variable memory management.

---

## 🛠️ Getting Started

### Prerequisites
* A standard C compiler (`cc`, `gcc`, or `clang`)
* `make` utility

### Installation & Compilation

1. Clone the repository into your project folder:
   ```bash
   git clone [https://github.com/yuuryyy/lib.git](https://github.com/yuuryyy/lib.git)
   cd lib
   ```

2. Compile the complete library:
   ```bash
   make
   ```
   This command will compile all objects from all three directories and archive them into a single `libft.a` file.

### Makefile Rules

* `make` / `make all`: Compiles the entire library (`Libft`, `Ft_printf`, and `Get_next_line`).
* `make clean`: Removes all `.o` object files across all directories.
* `make fclean`: Executes `clean` and also removes the `libft.a` binary.
* `make re`: Runs `fclean` followed by `all` to recompile everything from scratch.

---
*Developed by Youssra Chagri at 1337 (UM6P).*
