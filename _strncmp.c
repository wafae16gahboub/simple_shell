#include "shell.h"

/**
 * _strncmp - compares the first n charactes of the passed two strings
 *
 * @s1: first string
 * @s2: second string
 * @n: number of characters
 *
 * Return: an integer
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	int diff;
	size_t i;

	for (i = 0; i < n; i++)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			return (diff);
	}
	return (diff);
}
