#include "shell.h"

/**
 * is_delimiter - a function that checks if a character is a delimiter
 *
 * @c: a character to be checked.
 * @delims: a string of delimiters
 *
 * Return: True if it is a delimiter, else false.
 */

bool is_delimiter(char c, char *delims)
{
	int i;

	for (i = 0; delims[i]; i++)
	{
		if (c == delims[i])
		{
			return (true);
		}
	}
	return (false);
}
