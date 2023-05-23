#include "shell.h"

/**
 * env_handler - a function that handles the builtin env printing
 *
 * @args: the arguments that passed with env command
 * @nbr_of_args: number of args that passed with env cmd
 *
 * Return: Nothing
 */

void env_handler(char **args, size_t nbr_of_args)
{
	int i;

	if (!args[1])
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
	}

	free_vector(args, nbr_of_args);
}
