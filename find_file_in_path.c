#include "shell.h"

/**
 * find_file_in_path - Searches for a file in the directories specified
 *			in the PATH environment variable.
 *
 * @filename: The name of the file to search for.
 * @statbuf: Pointer to the struct stat object to store the file status.
 *
 * Return: A full path string or NULL
 */

char *find_file_in_path(char *filename, struct stat *statbuf)
{
	size_t i, nbr_of_args;
	char *fullpath = NULL, *current_path, **paths;

	current_path = _getenv("PATH");
	if (!current_path)
		return (NULL);

	paths = str_split_arr(current_path, ":", &nbr_of_args);
	if (!paths)
		return (NULL);

	for (i = 0; i < nbr_of_args; i++)
	{
		fullpath = concatStrings(paths[i], "/", filename);
		if (does_file_exist(fullpath, statbuf))
		{
			free_vector(paths, nbr_of_args);
			return (fullpath);
		}
		free(fullpath);
		fullpath = NULL;
	}

	free_vector(paths, nbr_of_args);
	free(fullpath);
	return (NULL);
}
