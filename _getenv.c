#include "headers.h"
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
/**
 * _getenv - gets environment variable
 * @name: name of variable
 * Return: value
 */
char *_getenv(const char *name)
{
	int len = _strlen((char *)name);
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		if (_strncmp(*env, (char *)name, len) == 0 && env[0][len] == '=')
			return (*env + len + 1);
		env++;
	}
	return (NULL);
}
int main(void)
{
	printf("real getenv: %s\n", getenv("PATH"));
	printf("my getenv: %s\n", _getenv("PATH"));
	return (0);
}
