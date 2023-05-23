#include "shell.h"
/**
 * concatStrings - Concatenates three strings into a single string.
 *
 * @str1: The first input string.
 * @str2: The second input string.
 * @str3: The third input string.
 *
 * Return: A pointer to the concatenated string or NULL if an error occurs.
 *		must be freed with free()
 */
char *concatStrings(const char *str1, const char *str2, const char *str3)
{
	size_t len1, len2, len3;
	char *result;

	if (!str1 || !str2 || !str3)
		return (NULL);

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	len3 = _strlen(str3);
	if (len1 == 0 || len2 == 0 || len3 == 0)
		return (NULL);

	result = malloc((len1 + len2 + len3 + 1) * sizeof(char));
	if (!result)
		return (NULL);

	_strcpy(result, str1);
	_strcat(result, str2);
	_strcat(result, str3);
	return (result);
}
