#include "main.h"

 /**
 * _numlen - calculates the number of digits.
 * @n: the number.
 *
 * Return: the number of digits in n.
 */
int _numlen(int n)
{
	int len = 0;

	if (n == 0)
		return (1);

	if (n < 0)
	{
		len++;
		n = -n;
	}

	while (n != 0)
	{
		n /= 10;
		len++;
	}

	return (len);
}
