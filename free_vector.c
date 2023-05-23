#include "shell.h"

/**
 * free_vector - A function that frees a two dimensional array
 *
 * @vector: the array to be freed
 * @len: array's length
 *
 * Return: Nothing
 */

void free_vector(char **vector, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++)
		free(vector[i]);

	free(vector);
}
