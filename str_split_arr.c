#include "shell.h"

/**
 * str_split_arr - Splits a string into an array of words based on a delimiter
 *
 * @str: The input string to be split.
 * @delim: The delimiter used to split the string.
 * @arrLen: A pointer to store the number of words in the array.
 *
 * Return: A dynamically allocated array of strings or NULL if an error occurs
 */

char **str_split_arr(char *str, char *delim, size_t *arrLen)
{
	char **words, *pStr = str;
	unsigned int i, j, nbr_of_words, word_sizes[MAX_WORDS];

	set_arr_to_zeros(word_sizes, MAX_WORDS);
	nbr_of_words = count_words(str, delim, word_sizes);

	if (nbr_of_words == 0)
		return (NULL);

	words = malloc((sizeof(char *) * (nbr_of_words + 1)));
	if (!words)
		return (NULL);

	for (i = 0; i < nbr_of_words; i++)
	{
		words[i] = malloc((sizeof(char) * word_sizes[i]) + 1);
		if (!words[i])
		{
			free_vector(words, i);
			return (NULL);
		}

		for (j = 0; j < word_sizes[i]; j++, pStr++)
		{
			while (is_delimiter(*pStr, delim))
				pStr++;
			words[i][j] = *pStr;
		}
		words[i][j] = '\0';
	}

	*arrLen = nbr_of_words;
	words[i] = NULL;

	return (words);
}
