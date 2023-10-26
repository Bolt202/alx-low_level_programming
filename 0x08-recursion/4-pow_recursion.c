#include "main.h"

/**
 * _pow_recursion - Computes the power of a number recursively.
 * @x: The base.
 * @y: The exponent.
 *
 * Return: The result of x^y. If y is negative, returns -1.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}

