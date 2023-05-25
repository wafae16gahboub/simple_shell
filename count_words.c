#include "shell.h"

/**
 * count_words - counts the number of words in a string seperated by
 *		 one or more delimiter.and it counts the length of
 *		 each word and stores them in an array.
 * @string: a string
 * @delimiters: a string of One or more delimiters to separate the string
 * @word_counts_arr: a pointer to an array where
 *		the word's lengths will be stored
 *
 * Return: Number of words
 */

int count_words(char *string, char *delimiters, unsigned int *word_counts_arr)
{
	int num_words = 0, i;
	bool inside_word = false, is_delimiter = false;

	if (!string)
		return (0);

	for (; *string; string++)
	{
		is_delimiter = false;
		for (i = 0; delimiters[i]; i++)
		{
			if (*string == delimiters[i])
			{
				is_delimiter = true;
				break;
			}
		}

		if (is_delimiter)
			inside_word = false;
		else
		{
			if (!inside_word)
			{
				word_counts_arr[num_words] = 0;
				inside_word = true;
				num_words++;
			}
			word_counts_arr[num_words - 1]++;
		}
	}
	return (num_words);
}
