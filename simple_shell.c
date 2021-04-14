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
		isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "$ ", 2) : status;
		if (getline(&line, &l_len, stdin) == -1)
			break;
		if (*line == '\n')
			break;

		command = s_tok(line);

		check_builtin(line, command);

		child = fork();
		if (child == -1)
			exit(EXIT_FAILURE);
		if (child == 0)
		{
			if (execve(findpath(command[0]), command, environ) == -1)
				exit(EXIT_FAILURE);
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
	isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "\n", 1) : status;
	free(line);
	exit(status);
}
