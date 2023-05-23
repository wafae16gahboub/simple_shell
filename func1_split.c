#include "mon_shel.h"
/**
 * **split_path -  Splits a string
 * @ptr: pointer
 * by wafa et simo
 * Return: An array of strings
 */
char **split_path(char *ptr)
{
char *ken;
char **rect = malloc(sizeof(char *) * MAX_ARGS);
int n = 0;

ken = strtok(ptr, ":");
while (ken != NULL)
{
rect[n] = ken;
ken = strtok(NULL, ":");
n++;
}
rect[n] = NULL;
return (rect);
}
/**
 * detect_find - Searches for a file in a given directory list
 * @grid: The file to search for
 * @dest: An array of directories to search in
 * by wafa et simo
 * Return: A pointer to the found file's path if found, or NULL otherwise
 */
char *detect_find(char *grid, char **dest)
{
int i;
char *ptr = malloc(BUFFER_SIZE);
if (grid[0] == '/' || grid[0] == '.')
{
if (access(grid, X_OK) == 0)
return (grid);
}
else
{
for (i = 0; dest[i] != NULL; i++)
{
_strcpy(ptr, dest[i]);
_strcat(ptr, "/");
_strcat(ptr, grid);
if (access(ptr, X_OK) == 0)
return (ptr);
}
}
free(ptr);
return (NULL);
}
/**
 * ecut_com - Execute a command based on the provided path and arguments
 * @comme_pathe: The path of the command to execute
 * @argc: An array of command arguments
 * @argv: The command itself and its arguments
 * by wafa & simo
 * Return: 0
 */
void ecut_com(char *comme_pathe, char **argc, char *argv[])
{
int i;
if (_strcmp(argc[0], "exit") == 0)
{
exit(EXIT_SUCCESS);
}
else if (_strcmp(argc[0], "env") == 0)
{
for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
return;
}
if (comme_pathe != NULL)
{
pid_t pid = fork();
if (pid < 0)
{
perror(comme_pathe);
}
if (pid == 0)
{
if (execve(comme_pathe, argc, NULL) == -1)
{
perror("Execution failed");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
free(comme_pathe);
}
else
{
printf("%s: No such file or directory\n", argv[0]);
}
}
