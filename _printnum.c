 #include "main.h"

 /**
 * _print_num - writes a number to stdout.
 * @n: the number to write
 *
 * Return: the number of characters written
 */
int _print_num(int n)
{
	int len;
	char buf[20];
	int count = 0;
	int i;

	len = _numlen(n);
	i = len--;
	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else if (n < 0)
	{
	    _putchar('-');
	    count++;
	    n = -n;
	}

	while (n != 0)
	{
		buf[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}

	count += _puts(&buf[i + 1]);
	return (count);
}
