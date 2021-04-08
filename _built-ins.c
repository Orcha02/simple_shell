#include "headers.h"
/**
 * b_env - prints the environment
 * @ac: argument count
 * @av: argument value
 * @env: environ
 * Return: always 0
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
