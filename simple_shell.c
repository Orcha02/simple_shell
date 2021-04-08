#include "headers.h"

/**
 * simple_shell - UNIX command line interpreter
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t child;
	char *line = NULL, **command = NULL;
	char *b_exit = "exit", *b_env = "env";
	size_t l_len = 0;
	int status = 0;

	while (1)
	{
		/*printf("$ ");*/
		isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "$ ", 2) : status;
		if (getline(&line, &l_len, stdin) == -1)
			break;

		if (*line == '\n')
			break;

		command = s_tok(line);

		if (_strncmp(command[0], b_exit, 4) == 0)
		{
			_free_parent(line, command);
			exit(0);
		}
		if (_strncmp(command[0], b_env, 3) == 0)
		{
			built_env(environ);
		}
		child = fork();
		if (child == 0)
		{
			if (execve(findpath(command[0]), command, NULL)) /*envp*/
			{
				perror("execve");
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
	isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "\n", 1) : status;
	free(line);
	exit(status);
}
