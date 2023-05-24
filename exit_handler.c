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
	int status = EXIT_SUCCESS, i;

	if (nbr_of_args > 1)
	{
		for (i = 0; args[1][i] != '\0'; i++)
		{
			if (!isdigit(args[1][i]))
			{
				perror("Illegal number");
				free_vector(args, nbr_of_args);
				return;
			}
		}
		status = atoi(args[1]);
	}

	free_vector(args, nbr_of_args);
	exit(status);
}
/*
*void exit_handler(char **args, size_t nbr_of_args)
*{
*	int status = EXIT_SUCCESS;
*
*	if (args[1])
*		status = _atoi(args[1]);
*
*	free_vector(args, nbr_of_args);
*	exit(status);
*}
*/
