#include "shell.h"

/**
 * _getenv - give back the value of a given env variable
 *
 * @name: the name of that variable
 *
 * Return: a pointer to variable value
 */

char *_getenv(char *name)
{
	size_t len;
	char **env = environ;

	if (!name || *name == '\0')
		return (NULL);

	len = _strlen(name);

	while (*env)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
			return (&((*env)[len + 1]));

		env++;
	}
	return (NULL);
}
