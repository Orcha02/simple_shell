#include "headers.h"
/**
 * simple_shell - UNIX command line interpreter
 * Return: Always 0 (Success)
 */

int main(void)
{
	pid_t child;
	char *tok, *line = NULL, **command = NULL, separator[] = {" \t\n\r"};
	size_t i, l_len = 0;
	int status, count_tok;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&line, &l_len, stdin) == -1)
			break;
		tok = strtok(line, separator);
		for (i = 0; tok != '\0'; i++)
		{
			tok = strtok(NULL, separator);
			count_tok++;
		}
		command = malloc(sizeof(char *) * (count_tok + 1));
		tok = strtok(line, separator);
		for (i = 0; i < 20 && tok != NULL; i++)
		{
			command[i] = tok;
			tok = strtok(NULL, separator);
		}
		command[i] = NULL;
		child = fork();
		if (child == 0)
		{
			if (execve(command[0], command, NULL)) /*envp*/
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		if (child > 0)
			wait(&status);
	}
	printf("\n");
	free(line);
	exit(status);
}
