#include "headers.h"

/**
 * find_length - calculate the lenght of command line
 *@s: char pointer
 * Return: length of pointer
 */
unsigned int find_length(char *s)
{
	unsigned int count_tok = 0, i = 0, flag = 0;

	while (s[i] != '\0')
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
	return (count_tok);
}

/**
 * s_tok - separate line in tokens
 * @str: command line
 * Return: char
 */
char **s_tok(char *str)
{
	char separator[] = " \t\n\r";
	char **command, *tok;
	unsigned int len, i;

	str[_strlen(str) - 1] = '\0';
	len = find_length(str);
	if (len == 0)
		return ('\0');

	command = malloc((sizeof(char *) * (len + 1)));
	if (command == NULL)
		return ('\0');

	i = 0;
	tok = strtok(str, separator);
	while (tok != NULL)
	{
		command[i] = malloc(_strlen(tok) + 1);
		if (command[i] == NULL)
		{
			_free_double_pointer(command);
			return ('\0');
		}
		strncpy(command[i], tok, _strlen(tok) + 1);
		tok = strtok(NULL, separator);
		++i;
	}
	command[i] = NULL;
	return (command);
}
