#include "headers.h"

/**
 * main - UNIX command line interpreter
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t child;
	char *line = NULL, **command = NULL;
	size_t l_len = 0;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &l_len, stdin) == EOF)
			break;
		if (*line == '\n')
			continue;

		command = s_tok(line);
		check_builtin(line, command);

		child = fork();
		if (child == -1)
			exit(EXIT_FAILURE);
		if (child == 0)
		{
			if (execve(findpath(command[0]), command, environ) == -1)
			{
				_free_parent(line, command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (command == NULL)
				_free_parent(line, command);
			else
				_free_parent(line, command);
		}
		line = NULL;
	}
	free(line);
	exit(status);
}
