#include "shell.h"
/**
 * spec - Find and return the corresponding function for a given command.
 *
 * Description:
 * - Searches for the specified command in the `specses` array and returns
 *   the associated function pointer.
 *
 * @s: The command string to find.
 *
 * Return:
 * - If the command is found, returns the corresponding function pointer.
 * - If the command is not found, returns NULL.
 *
 * Authors:
 * - MahmoudMetwalli
 * - AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int (*spec(char *s))(char **argv, char *buff, int status, int round_index)
{
	specs specses[] = {
		{"exit", main_exit},
		{"env", print_env},
		{NULL, NULL}};
	int g = 0;

	while (specses[g].sp)
	{
		if (!_strcmp(s, specses[g].sp))
		{
			return (specses[g].f);
		}
		g++;
	}
	return (NULL);
}
