#include "headers.h"
/**
 * b_exit - Checks for an exit
 * @command: array
 * Return: void
 */
int b_exit(char *command)
{
	char *b_exit;
	char _exit[] = "exit";

	b_exit = _exit;
	if (_strncmp(command, b_exit, 4) == 0)
	{
		return (0);
	}
	return (1);
}
