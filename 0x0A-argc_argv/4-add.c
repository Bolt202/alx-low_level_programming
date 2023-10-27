#include <stdio.h>
#include "main.h"

/**
 * check_num - Checks if a string is a numeric digit.
 * @s: The string to check.
 *
 * Return: 1 if the string is a numeric digit, 0 otherwise.
 */
int check_num(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - Adds two numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 (Success), 1 (Error).
 */
int main(int argc, char *argv[])
{
	int sum = 0;

	if (argc != 3 || !check_num(argv[1]) || !check_num(argv[2]))
	{
		printf("Error\n");
		return (1);
	}

	sum = atoi(argv[1]) + atoi(argv[2]);
	printf("%d\n", sum);

	return (0);
}

