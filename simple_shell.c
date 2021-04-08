#include "headers.h"


void free_all_double_ptr(char **d_ptr)
{
	unsigned int i = 0;

	if (d_ptr == NULL)
		return;

	while (d_ptr[i])
	{
		free(d_ptr[i]);
		++i;
	}

	if (d_ptr[i] == NULL)
		free(d_ptr[i]);

	free(d_ptr);
}
void parent_free_buff_commands(char *buffer, char **commands)
{
	free(buffer);
	free_all_double_ptr(commands);
}

unsigned int find_lenght(char *s)
{
	unsigned int count_tok = 0, i = 0, flag = 0;

       	while(s[i] != '\0')
	{

		if (s[i] != ' ')
			flag = 1;

		if ((flag && s[i + 1] == ' ') || (flag && s[i + 1] == '\0'))
		{
			++count_tok;
			flag = 0;
		}
		++i;
	}
	return(count_tok);
}


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
				free_all_double_ptr(command);
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
		/*	if (space_line(line) == 0)
			continue;*/
		else
		{
			wait(&status);
			if (command == NULL)
				parent_free_buff_commands(line, command);
			else
				parent_free_buff_commands(line, command);

		}
		line = NULL;
	}
	isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "\n", 1) : status;
	free(line);
	exit(status);
}
