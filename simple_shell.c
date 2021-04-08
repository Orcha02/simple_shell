#include "headers.h"

/**
 * simple_shell - UNIX command line interpreter
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t child;
	char *tok = NULL, *line = NULL, **command = NULL, separator[] = " \t\n\r";
	size_t i, l_len = 0;
	int status = 0;
	unsigned int len = 0;

	while (1)
	{
		/*printf("$ ");*/
		isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "$ ", 2) : status;
		if (getline(&line, &l_len, stdin) == -1)
			break;

		if (*line == '\n')
			break;

		line[strlen(line) - 1] = '\0';
		len = find_lenght(line);
		if (len == 0)
			return ('\0');

		command = malloc((sizeof(char *) * (len + 1)));
		if (command == NULL)
			return ('\0');

		i = 0;
		tok = strtok(line, separator);
		while (tok != NULL)
		{
			command[i] = malloc(strlen(tok) + 1);
			if (command[i] == NULL)
			{
				_free_double_pointer(command);
				return ('\0');
			}
			strncpy(command[i], tok, strlen(tok) + 1);
			tok = strtok(NULL, separator);
			++i;
		}
		command[i] = NULL;

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
