# C-preprocessor
A custom C preprocessor implemented in C on Linux
# Custom C Preprocessor

A simple custom C preprocessor implemented in C on Linux/WSL.

This project replicates the basic preprocessing stages of a C compiler, including comment removal, file inclusion, and macro replacement.

## Features

- Removes single-line (`//`) and multi-line (`/* */`) comments.
- Handles comments inside string and character literals.
- Processes `#include` directives.
- Supports local and system header files.
- Replaces object-like macros without arguments.
- Replaces function-like macros with arguments.
- Removes `#define` directives after macro replacement.
- Generates a preprocessed `.i` file.

## Project Structure

```text
c-custom-preprocessor/
├── main.c
├── comment_removal.c
├── file_inclusion.c
├── macro_handler.c
├── header.h
├── Makefile
└── README.md
```

## Requirements

- C compiler (GCC)
- Linux or WSL
- Make

## Compilation

```bash
make
```

## Usage

```bash
./mypreprocessor filename.c
```

Example:

```bash
./mypreprocessor sample.c
```

The program generates:

```text
sample.i
```

## Preprocessing Steps

1. Read the input C file.
2. Remove comments.
3. Process file inclusion.
4. Replace macros.
5. Generate the `.i` output file.

## Note

This is an educational project that implements the basic concepts of C preprocessing. It is not a complete replacement for the standard C preprocessor.

## Author

C Programming Project
