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
	int status = EXIT_SUCCESS, i = 0, startAt = 0;

	if (nbr_of_args > 1)
	{
		if (args[1][0] == '-')
			startAt = 1;

		for (i = startAt; args[1][i] != '\0'; i++)
		{
			if (!isdigit(args[1][i]))
			{
				/*perror("Illegal number");*/
				fprintf(stderr, "Illegal number: %s\n", args[1]);
				free_vector(args, nbr_of_args);
				return;
			}
		}
		status = _atoi(args[1]);
	}

	free_vector(args, nbr_of_args);
	exit(status);
}
