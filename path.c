#include "shell.h"
/**
 * cmd_not_found - Print error message for command not found.
 *
 * Description:
 * - Prints an error message indicating that the
 * specified command was not found.
 * - Includes the round index and the name of the command in the message.
 *
 * @cmd: The name of the command.
 * @round_index: The current round index.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void cmd_not_found(char *cmd, int round_index)
{
	_puts("./hsh: ", 2);
	print_number_error(round_index);
	_puts(": ", 2);
	_puts(cmd, 2);
	_puts(": not found\n", 2);
	_putchar_error(-1);
}
/**
 * make_list - Create a list of directories from the PATH environment variable.
 *
 * Description:
 * - Retrieves the value of the PATH environment variable.
 * - Tokenizes the PATH variable using ':' as
 * a delimiter and stores each directory in a list.
 * - Returns the list of directories.
 *
 * Return:
 * - A list of directories from the PATH environment variable.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
char **make_list(void)
{
	char *path, *name = "PATH";
	static char *list[1024];
	int i = 0;

	path = _getenv(name);
	path = strtok(path, ":");
	while (path)
	{
		list[i] = path;
		path = strtok(NULL, ":");
		i++;
	}
	return (list);
}
/**
 * _getenv - Get the value of an environment variable.
 *
 * Description:
 * - Searches for the specified environment variable by name.
 * - Returns the value of the environment variable.
 *
 * @name: The name of the environment variable.
 *
 * Return:
 * - The value of the specified environment variable.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
char *_getenv(const char *name)
{
	char *result;
	static char tmp[1024];
	int i = 0;

	while (__environ[i])
	{
		_strcpy(tmp, __environ[i]);
		if (!strcmp(strtok(tmp, "="), name))
		{
			result = strtok(NULL, "=");
			return (result);
		}
		i++;
	}
	return (NULL);
}
/**
 * check_cmd - Check if a command is present in the given list of directories.
 *
 * Description:
 * - Checks if the specified command exists in the given list of directories.
 * - If found, returns the full path of the command.
 *
 * @cmd: The command to check.
 * @list: The list of directories to search for the command.
 *
 * Return:
 * - The full path of the command if found, otherwise NULL.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
char *check_cmd(char *cmd, char **list)
{
	char *path = NULL;
	static char cmd_path[1024];
	struct stat s;
	int i = 0;

	_strcpy(cmd_path, cmd);
	if (!stat(cmd_path, &s))
	{
		return (cmd_path);
	}
	path = list[i];
	while (list[i] && path && i < 8)
	{
		_strcpy(cmd_path, path);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		if (!stat(cmd_path, &s))
		{
			return (cmd_path);
		}
		i++;
		path = list[i];
	}
	return (NULL);
}
