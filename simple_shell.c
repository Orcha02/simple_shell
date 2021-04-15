#include "headers.h"
/**
 * main - UNIX command line interpreter
 * Return: Always 0 (Success)
 */
int main(void)
{	pid_t child;
	char *line = NULL, **command = NULL;
	size_t l_len = 0;
	int status = 0, retVal = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		signal(SIGINT, signintHandler);
		if (getline(&line, &l_len, stdin) == EOF)
			break;
		if (*line == '\n' || *line == '\t')
			continue;
		command = s_tok(line);
		if (command == NULL)
			continue;
		if (check_builtin(line, command, &retVal) == 0)
		{			child = fork();
			if (child == 0)
			{
				if (execve(findpath(command[0], &retVal), command, environ) == -1)
				{					_free_parent(line, command);
					exit(retVal);
				}
			}
			else
			{				wait(&status);
				_free_parent(line, command);
				if (WIFEXITED(status))
					retVal = WEXITSTATUS(status);
			}
			line = NULL;
		}
		else
			_free_double_pointer(command);
	}
	free(line);
	exit(status);
}
