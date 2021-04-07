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
	int status, count_tok, b;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &l_len, stdin) == EOF)
			break;

		for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] == separator[0] && line[i + 1] != '\0')
				count_tok++;
		}
		printf("%d\n", count_tok);

		command = malloc(sizeof(char *) * (count_tok + 1));
		tok = strtok(line, separator);
		command[0] = tok;

		for (i = 1; i <= count_tok && tok != NULL; i++)
		{
			printf("%s\n", tok);
			tok = strtok(NULL, separator);
			command[i] = tok;
			if (command[i] == NULL)
				break;
		}
		b = b_exit(command[0]);
		if (b == 0)
			break;
		child = fork();
		if (child == 0)
		{
			if (execve(findpath(command[0]), command, NULL)) /*envp*/
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
			free(line);
			free(command);
		}
		if (child > 0)
			wait(&status);
	}
	printf("\n");
	free(line);
	free(command);
	exit(status);
}
