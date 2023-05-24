#include "shell.h"

/**
 * exit_handler - a function that handles the built in exit cmd
 *
 * @args: the arguments that passed with exit cmd
 * @nbr_of_args: number of arguments passed with exit cmd
 *
 * Return: Nothing
 */

void exit_handler(char **args, size_t nbr_of_args)
{
	int status = EXIT_SUCCESS, i = 0;

	if (!args[1])
		exit(status);
	
	while (args[1][i])
	{
		if (!isdigit(args[1][i++]))
		{
			perror("Illegal number");
			return;
		}
	}
	status = _atoi(args[1]);

	free_vector(args, nbr_of_args);
	exit(status);
}
