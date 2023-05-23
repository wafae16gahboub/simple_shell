#include "shell.h"

/**
 * does_file_exist - A fucntion that checks if a file exists
 *
 * @path: path of the file
 * @buffer_status: the information about the file or directory will be stored
 *
 * Return: true if the file exists, and false if not
 */

bool does_file_exist(char *path, struct stat *buffer_status)
{
	if (stat(path, buffer_status) == 0)
		return (true);

	return (false);
}

