# Get Next Line

## Overview

The `get_next_line` project provides a function that reads a line from a file descriptor and returns it. This project is particularly useful for reading files line by line in an efficient manner. The function handles different edge cases such as empty files, files with only newline characters, and large lines.

## Features

- **Efficient Reading**: The function reads from a file descriptor using a buffer to optimize performance.
- **Edge Case Handling**: Properly handles various file scenarios including empty files, files with only newlines, and large lines without newlines.
- **Bonus**: The bonus part extends functionality to handle multiple file descriptors simultaneously.

## Function Documentation

### `get_next_line`

```c
char *get_next_line(int fd);
```

Reads a line from the file descriptor `fd` and returns it. The function reads until it encounters a newline character or reaches the end of the file.

### `test_get_next_line`

```c
void test_get_next_line(const char *file_path);
```

A helper function that opens a file, reads each line using `get_next_line`, and prints it to the standard output.

## Usage

### Testing the Function

The provided `main` function demonstrates how to test `get_next_line` with various test files. Each test file represents different edge cases:

```c
int main(void)
{
    test_get_next_line("tests/files/1char");
    printf("\n");
    test_get_next_line("tests/files/empty");
    printf("\n");
    test_get_next_line("tests/files/nl");
    printf("\n");
    test_get_next_line("tests/files/41_no_nl");
    printf("\n");
    test_get_next_line("tests/files/41_with_nl");
    printf("\n");
    test_get_next_line("tests/files/42_no_nl");
    printf("\n");
    test_get_next_line("tests/files/42_with_nl");
    printf("\n");
    test_get_next_line("tests/files/43_no_nl");
    printf("\n");
    test_get_next_line("tests/files/43_with_nl");
    printf("\n");
    test_get_next_line("tests/files/multiple_nlx5");
    printf("\n");
    test_get_next_line("tests/files/multiple_line_no_nl");
    printf("\n");
    test_get_next_line("tests/files/multiple_line_with_nl");
    printf("\n");
    test_get_next_line("tests/files/alternate_line_nl_no_nl");
    printf("\n");
    test_get_next_line("tests/files/alternate_line_nl_with_nl");
    printf("\n");
    test_get_next_line("tests/files/big_line_no_nl");
    printf("\n");
    test_get_next_line("tests/files/big_line_with_nl");
    return (0);
}
```

### Compilation

To compile the project, ensure all source files are included. For example:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o get_next_line
```

### Running Tests

To run the tests, simply execute the compiled binary:

```sh
./get_next_line
```

## Bonus

The bonus implementation extends the `get_next_line` function to support reading from multiple file descriptors simultaneously. This is useful in scenarios where you need to read from multiple files concurrently.

## Helper Functions

### `ft_strlen`

```c
int ft_strlen(char *str);
```

Calculates the length of a string.

### `ft_strlcpy`

```c
size_t ft_strlcpy(char *dst, char *src, size_t dstsize);
```

Copies a string to a destination buffer.

### `ft_strjoin`

```c
char *ft_strjoin(char *s1, char *s2);
```

Joins two strings into a new string.

### `ft_substr`

```c
char *ft_substr(char *s, unsigned int start, size_t len);
```

Extracts a substring from a string.

### `is_in_str`

```c
ssize_t is_in_str(char *s, char c);
```

Checks if a character is present in a string and returns its position.

