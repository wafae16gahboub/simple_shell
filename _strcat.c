#include "shell.h"
/**
 * _strcat - Concatinates two strings
 * @dest: string1
 * @src: string2
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
		*dest++ = *src++;

	*dest = *src;

	return (ptr);
}
