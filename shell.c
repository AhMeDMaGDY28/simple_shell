#include "shell.h"
/**
 * main - Entry point for the custom shell.
 *
 * Description:
 * - Reads commands from the user, executes them, and prints the result.
 * - Supports built-in commands and executing programs in the system's PATH.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Always returns 1.
 */
int main(void)
{
	char *buff = NULL, *argument, **list = make_list();
	char *argv[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	size_t len = 0, i, status = 0, round_index = 0;
	int (*buit_in)(char **, char *, int, int);

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		if (getline(&buff, &len, stdin) == -1)
		{
			free(buff);
			exit(status);
		}
		check_comment(buff);
		round_index++;
		argument = strtok(buff, " \t\n");
		i = 0;
		while (i < 10 && argument)
		{
			argv[i] = argument;
			argument = strtok(NULL, " \t\n");
			i++;
		}
		while (i < 10)
		{
			argv[i] = NULL;
			i++;
		}
		if (!argv[0])
			continue;
		if (!spec(argv[0]))
			status = execute(argv, list, round_index);
		else
		{
			buit_in = spec(argv[0]);
			status = buit_in(argv, buff, status, round_index);
		}
	}
	return (1);
}
