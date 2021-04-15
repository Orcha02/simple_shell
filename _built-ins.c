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
	char *b_exit = "exit", *b_env = "env";

	if (_strncmp(command[0], b_exit, 4) == 0)
	{
		_free_parent(line, command);
		exit(*retVal);
	}
	if (_strncmp(command[0], b_env, 3) == 0)
		built_env(environ);
}
/**
 * built_env - prints the environment
 * @environ: environ
 *
 * Return: void
 */
void built_env(char **environ)
{
	unsigned int i, length;

	i = 0;
	while (environ[i])
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}
