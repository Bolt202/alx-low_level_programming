#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings and returns the result.
 * @s1: The first string to concatenate.
 * @s2: The second string to concatenate.
 *
 * Return: A pointer to a newly allocated space containing the concatenated
 *         string. NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, k;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = j = k = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	concat = malloc(sizeof(char) * (i + j + 1));

	if (concat == NULL)
		return (NULL);

	i = j = 0;
	while (s1[i] != '\0')
	{
		concat[k] = s1[i];
		i++;
		k++;
	}

	while (s2[j] != '\0')
	{
		concat[k] = s2[j];
		k++;
		j++;
	}
	concat[k] = '\0';

	return (concat);
}

