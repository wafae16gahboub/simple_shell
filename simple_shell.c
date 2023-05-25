#include "shell.h"

/**
* main - a simple_shell that runs commands
* Return: Always 0 (Success)
*/

int main(void)
{
	char *buffer = NULL, *fullpath, **argv;
	size_t buffer_size = 0, word_count;
	bool is_from_pipe = false;
	struct stat buffer_status;

	while (true)
	{
		read_input(&buffer, &buffer_size, &is_from_pipe);
		argv = str_split_arr(buffer, "\t ", &word_count);
		if (!argv)
			continue;

		if (builtin_handler(argv, word_count, &buffer))
			continue;

		if (!does_file_exist(argv[0], &buffer_status))
		{
			fullpath = find_file_in_path(argv[0], &buffer_status);
			if (!fullpath)
			{
				perror("hsh");
				free_vector(argv, word_count);
				continue;
			}
			else
			{
				free(argv[0]);
				argv[0] = fullpath;
			}
		}

		execute_cmd(argv, word_count);
		free_vector(argv, word_count);
	}
	free(buffer);
	return (0);
}
