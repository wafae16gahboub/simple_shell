#include "shell.h"

/**
 * builtin_handler - Handles built-in commands.
 *
 * @args: Pointer to an array of command arguments.
 * @nbr_of_args: Number of arguments in the array.
 * @buffer: Pointer to the input buffer.
 *
 * Return: True if a built-in command was handled, otherwise false.
 */

bool builtin_handler(char **args, size_t nbr_of_args, char **buffer)
{
	if (_strncmp(args[0], "exit", 4) == 0)
	{
		free(*buffer);
		*buffer = NULL;
		exit_handler(args, nbr_of_args);
		return (true);
	}
	else if (_strncmp(args[0], "env", 3) == 0)
	{
		env_handler(args, nbr_of_args);
		return (true);
	}
	return (false);
}
