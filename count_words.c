#include "shell.h"

/**
 * count_words - counts the number of words in a string seperated by
 *		 one or more delimiter.and it counts the length of
 *		 each word and stores them in an array.
 * @str: a string
 * @separats: a string of One or more delimiters to separate the string
 * @arr: a pointer to an array where the word's lengths will be stored
 *
 * Return: Number of words
 */

int count_words(char *str, char *separats, unsigned int *arr)
{
	int words_count = 0, i;
	bool inside_word = false, is_separator = false;

	if (!str)
		return (0);

	while (*str)
	{
		is_separator = false;
		for (i = 0; separats[i]; i++)
		{
			if (*str == separats[i])
			{
				is_separator = true;
				break;
			}
		}

		if (is_separator)
			inside_word = false;
		else
		{
			if (!inside_word)
			{
				arr[words_count] = 0;
				inside_word = true;
				words_count++;
			}
			arr[words_count - 1]++;
		}

		str++;
	}
	return (words_count);
}
