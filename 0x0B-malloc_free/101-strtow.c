#include <stdlib.h>
#include "main.h"

/**
 * count_word - Helper function to count the number of words in a string.
 * @s: The string to evaluate.
 *
 * Return: The number of words.
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * allocate_memory - Allocates memory for an array of strings.
 * @words: The number of words to allocate.
 *
 * Return: A pointer to an array of strings (Success) or NULL (Error).
 */
char **allocate_memory(int words)
{
	char **matrix;

	matrix = (char **)malloc(sizeof(char *) * (words + 1));

	if (matrix == NULL)
		return (NULL);

	return (matrix);
}

/**
 * fill_matrix - Fills the matrix with words from the input string.
 * @matrix: The matrix to be filled.
 * @str: The input string.
 */
void fill_matrix(char **matrix, char *str)
{
	char *tmp;
	int i, k = 0, c = 0, start, end;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *)malloc(sizeof(char) * (c + 1));

				if (tmp == NULL)
					return;

				while (start < end)
					*tmp++ = str[start++];

				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (Success) or NULL (Error).
 */
char **strtow(char *str)
{
    int words;

    if (str == NULL || *str == '\0')
        return (NULL);

    char **matrix;  // Declare the variable first

    words = count_word(str);

    if (words == 0)
        return (NULL);

    matrix = allocate_memory(words);  // Assign the value on a separate line

    if (matrix == NULL)
        return (NULL);

    fill_matrix(matrix, str);

    return (matrix);
}

