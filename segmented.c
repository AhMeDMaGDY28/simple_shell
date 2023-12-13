#include "shell.h"
/**
 * execute - Execute a command.
 *
 * Description:
 * - Attempts to execute a command, searching
 * for it in the provided list of paths.
 * - Handles forking and waiting for the child process.
 *
 * @argv: An array of strings representing the command and its arguments.
 * @list: A list of paths where the command might be located.
 * @round_index: The index of the current command in the shell's round.
 *
 * Return:
 * - Returns the exit status of the command.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int execute(char **argv, char **list, int round_index)
{
	char *cmd, *path;
	int status = 0, fork_call, es = 0;

	cmd = argv[0];
	path = check_cmd(cmd, list);
	if (!path)
	{
		cmd_not_found(cmd, round_index);
		status = 127;
	}
	else
	{
		argv[0] = path;
		fork_call = fork();
		if (fork_call == -1)
		{
			perror("Error:");
			return (1);
		}
		if (fork_call == 0)
		{
			execve(argv[0], argv, __environ);
		}
		else
		{
			wait(&status);
			es = WEXITSTATUS(status);
			status = es;
		}
	}
	return (status);
}
