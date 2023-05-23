#include "shell.h"

/**
 * _strlen - Calculates the length of a string
 * @s: string
 * Return: a number
 */

int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
