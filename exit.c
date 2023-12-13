#include "shell.h"
/**
 * _isdigit - Check if a character is a digit (0 through 9).
 *
 * Description:
 * - Checks if the given character is a digit.
 *
 * @c: The character to be checked.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoi_exit - Convert a string to an integer and handle exit codes.
 *
 * Description:
 * - Converts the given string to an integer.
 * - Handles exit codes for non-digit characters.
 * - Ensures the result is within the range [0, 256).
 *
 * @string: The string to be converted to an integer.
 * @round_index: The current round index.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The converted integer if successful.
 * - 257 if a non-digit character is encountered.
 */
int _atoi_exit(char *string, int round_index)
{
	short digit_found = 0;
	int sign = -1, result = 0, i = 0;

	while (string[i] != '\0')
	{
		if (!_isdigit(string[i]))
		{
			print_exit_error(string, round_index);
			return (257);
		}
		if (string[i] >= '0' && string[i] <= '9')
		{
			result *= 10;
			result -= (string[i] - '0');
			digit_found = 1;
		}
		else if (digit_found == 1)
			break;
		i++;
	}
	result *= sign;
	while (result > 256)
	{
		result -= 256;
	}
	return (result);
}
/**
 * print_exit_error - Print an exit error message.
 *
 * Description:
 * - Prints an error message for an illegal exit code.
 *
 * @string: The string containing the illegal exit code.
 * @round_index: The current round index.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void print_exit_error(char *string, int round_index)
{
		_puts("./hsh: ", 2);
		print_number_error(round_index);
		_puts(": exit: Illegal number: ", 2);
		_puts(string, 2);
		_putchar_error('\n');
		_putchar_error(-1);
}
/**
 * main_exit - Implement the exit built-in command.
 *
 * Description:
 * - Exits the shell with a specified exit code.
 * - If no exit code is provided, it exits with the status of the last command.
 * - Handles the case of an illegal exit code.
 *
 * @argv: The array of command arguments.
 * @buff: The buffer containing the command.
 * @status: The exit status of the shell.
 * @round_index: The current round index.
 *
 * Return:
 * - Always returns 0 to indicate successful execution.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int main_exit(char **argv, char *buff, int status, int round_index)
{
	if (!argv[1])
	{
		free(buff);
		exit(status);
	}
	status = _atoi_exit(argv[1], round_index);
	if (status == 257)
		return (2);
	free(buff);
	exit(status);
	return (0);
}
