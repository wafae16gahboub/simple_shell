#include "shell.h"

/**
 * execute_cmd - a function that execute cmd and handle error if occures
 *
 * @args: the command to execute
 * @nbr_of_args: the number of args passed with the cmd
 *
 * Return: Nothing
 */

void execute_cmd(char **args, size_t nbr_of_args)
{
	pid_t pid;
	int wstatus;

	pid = fork();
	if (pid == -1)
	{
		free_vector(args, nbr_of_args);
		perror("Error (fork)");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(args[0], args, environ);

		free_vector(args, nbr_of_args);
		perror("Error (execute_cmd)");
		exit(EXIT_FAILURE);
	}
	if (waitpid(pid, &wstatus, 0) == -1)
	{
		free_vector(args, nbr_of_args);
		perror("Error (waipid)");
		exit(EXIT_FAILURE);
	}
}
