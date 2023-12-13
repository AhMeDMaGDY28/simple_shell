#include "shell.h"
/**
 * check_comment - Check for a comment in the given buffer and truncate the
 *                 string at the '#' character if found.
 *
 * Description:
 * - Searches for the '#' character in the input buffer and truncates the
 *   string at that position if the character is found.
 *
 * @buff: The input buffer to check for comments.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void check_comment(char *buff)
{
	int i = 0;

	while (buff[i])
	{
		if (buff[i] == '#')
		{
			while (buff[i])
			{
				buff[i] = '\0';
				i++;
			}

			return;
		}
		i++;
	}
}
