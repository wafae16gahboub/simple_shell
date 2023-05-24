#include "shell.h"

/**
 * read_input - Reads input from stdin into a buffer.
 *
 * @buffer: Pointer to a pointer to the buffer to store the input line.
 * @buffer_size: Pointer to the size of the buffer.
 * @is_from_pipe: Pointer to a boolean indicating if the input is from a pipe.
 *
 * Return: Nothing
 */

void read_input(char **buffer, size_t *buffer_size, bool *is_from_pipe)
{
	ssize_t bytes_size;

	if (isatty(STDIN_FILENO) == 0)
		*is_from_pipe = true;
	else
		write(STDOUT_FILENO, "$ ", 2);

	bytes_size = getline(buffer, buffer_size, stdin);

	if (bytes_size == -1)
	{
		free(*buffer);
		perror("Error (getline)");
		exit(EXIT_SUCCESS);
	}

	if ((*buffer)[bytes_size - 1] == '\n')
		(*buffer)[bytes_size - 1] = '\0';
}
