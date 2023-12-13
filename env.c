#include "shell.h"
/**
 * print_env - Print the current environment variables.
 *
 * Description:
 * - Prints the current environment variables to the standard output.
 *
 * @argv: Array of strings representing the command and its arguments.
 * @buff: The input buffer (unused in this function).
 * @status: The exit status (unused in this function).
 * @round_index: The current round index (unused in this function).
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return: Always 0.
 */
int print_env(char **argv, char *buff, int status, int round_index)
{
	int i = 0;

	(void)argv;
	(void)buff;
	(void)status;
	(void)round_index;
	while (__environ[i])
	{
		_puts(__environ[i], 1);
		_putchar('\n');
		i++;
	}
	_putchar(-1);
	return (0);
}
