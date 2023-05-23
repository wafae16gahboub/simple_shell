#include "shell.h"

/**
 * set_arr_to_zeros - a function that set an array to zeros
 *
 * @arr: the array
 * @size: the size of the array
 *
 * Return: Nothing
 */

void set_arr_to_zeros(unsigned int *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		arr[i] = '\0';
}
