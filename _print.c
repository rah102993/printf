#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _print_octal - writes a character to print octal integer.
 * @n: unsigned integer parameter.
 *
 * Return: 1 on success, -1 on error
 */
int _print_octal(unsigned int n)
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

	while (n != 0)
	{
		buf[i] = (n % 8) + '0';
		n /= 8;
		i--;
	}

	count += _puts(&buf[i + 1]);
	return (count);
}
/**
 * _print_hex - writes a character to print hexadecimal integer.
 * @n: unsigned integer parameter.
 * @is_upper: uppercase character parameter.
 *
 * Return: 1 on success.
 */
int _print_hex(unsigned int n, int is_upper)
{
	int len;
	char buf[20];
	int count = 0;
	int i, remainder;

	len = _numlen(n);
	i = len--;
	if (n == 0)
	{
		_putchar('0');
		count++;
	}

	while (n != 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			buf[i] = remainder + '0';
		else if (is_upper)
			buf[i] = remainder - 10 + 'A';
		else
			buf[i] = remainder - 10 + 'a';

		n /= 16;
		i--;
	}

	count += _puts(&buf[i + 1]);
	return (count);
}
/**
 * _puts - writes a null-terminated string to stdout
 * @str: the string to write
 *
 * Return: the number of characters written
 */
int _puts(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
 /**
 * _printf - a custom implementation of printf
 * @format: a string containing format specifiers
 * @...: the arguments to replace the format specifiers
 *
 * Return: the number of characters written
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, d;
	char c;
	char *s;
	unsigned int u;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* skip '%' */

			if (*format == 'c')
			{
				c = (char) va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				count += _puts(s);
			}
			else if (*format == 'u')
			{
				u = va_arg(args, unsigned int);
				count += _print_num(u);
			}
			else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(args, int);
				count += _print_num(d);
			}
			else if (*format == 'o')
			{
				u = va_arg(args, unsigned int);
				count += _print_octal(u);
			}
			else if (*format == 'x' || *format == 'X')
			{
				u = va_arg(args, unsigned int);
				count += _print_hex(u, (*format == 'X'));
			}
			else
	{
		_putchar(*format);
		count++;
	}

	format++;
		}

		va_end(args);

		return (count);
	}
