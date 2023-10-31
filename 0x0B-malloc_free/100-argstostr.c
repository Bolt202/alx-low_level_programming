#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates the arguments in a double pointer array.
 * @ac: The number of arguments.
 * @av: A double pointer to an array of strings.
 *
 * Return: A pointer to a newly allocated space containing the concatenated
 * strings with newline characters. NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	int i, n, r = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
			l++;
	}
	l += ac;

	str = malloc(sizeof(char) * (l + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
		{
			str[r] = av[i][n];
			r++;
		}

		if (str[r] == '\0')
		{
			str[r++] = '\n';
		}
	}

	return (str);
}

