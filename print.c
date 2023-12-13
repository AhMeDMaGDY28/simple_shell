#include "shell.h"
/**
 * _puts - Prints a string to the standard output or standard error.
 *
 * Description:
 * - Prints the characters of the string to either standard output (i == 1)
 *   or standard error (i == 2).
 *
 * @s: The input string.
 * @i: Indicator for standard output (1) or standard error (2).
 *
 * Return:
 * - The number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int _puts(char *s, int i)
{
	char *f = s;

	if (i == 1)
	{
		while (*s)
		{
			_putchar(*s++);
		}
	}
	else if (i == 2)
	{
		while (*s)
		{
			_putchar_error(*s++);
		}
	}
	return (s - f);
}
/**
 * _putchar - Writes a character to the standard output or flushes the buffer.
 *
 * Description:
 * - Writes a character to the buffer. If i is -1 or the buffer is full,
 *   the buffer is flushed to the standard output.
 *
 * @i: The character to be written to the buffer.
 *
 * Return:
 * - Always returns 1.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int _putchar(int i)
{
	static int j;
	static char buffer[1024];

	if (i == -1 || j >= 1024)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (i != -1)
		buffer[j++] = i;
	return (1);
}
/**
 * _putchar_error - Writes a character to the standard error
 * or flushes the buffer.
 *
 * Description:
 * - Writes a character to the error buffer. If i is -1 or the buffer is full,
 *   the buffer is flushed to the standard error.
 *
 * @i: The character to be written to the error buffer.
 *
 * Return:
 * - Always returns 1.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int _putchar_error(int i)
{
	static int j;
	static char buffer_error[1024];

	if (i == -1 || j >= 1024)
	{
		write(2, buffer_error, j);
		j = 0;
	}
	if (i != -1)
		buffer_error[j++] = i;
	return (1);
}
/**
 * print_number - Prints an integer to the standard output.
 *
 * Description:
 * - Prints an integer to the standard output, handling negative numbers.
 *
 * @n: The integer to be printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void print_number(int n)
{
	unsigned int k, m;

	if (n == 0)
	{
		_putchar('0');
	}
	else
	{
		if (n < 0)
		{
			k = -n;
			_putchar('-');
		}
		else
		{
			k = n;
		}
		m = 1000000000;
		do {
			if (k >= m)
			{
				_putchar((k / m % 10) + '0');
			}
			m /= 10;
		} while (m != 0);
	}
}
/**
 * print_number_error - Prints an integer to the standard error output.
 *
 * Description:
 * - Prints an integer to the standard error output, handling negative numbers.
 *
 * @n: The integer to be printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void print_number_error(int n)
{
	unsigned int k, m;

	if (n == 0)
	{
		_putchar_error('0');
	}
	else
	{
		if (n < 0)
		{
			k = -n;
			_putchar_error('-');
		}
		else
		{
			k = n;
		}
		m = 1000000000;
		do {
			if (k >= m)
			{
				_putchar_error((k / m % 10) + '0');
			}
			m /= 10;
		} while (m != 0);
	}
}
