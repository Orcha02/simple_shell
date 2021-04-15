#include "headers.h"

/**
 * check_builtin - execute built-ins
 *@line: command line
 *@command: separate tokens
 *@retVal: return value of exit
 * Return: void
 */

void check_builtin(char *line, char **command, int *retVal)
{
	char *b_exit = "exit";

	if (_strncmp(command[0], b_exit, 4) == 0)
	{
		_free_parent(line, command);
		exit(*retVal);
	}
}
