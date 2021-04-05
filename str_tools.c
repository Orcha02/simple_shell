#include "headers.h"
/**
 * _strlen - Function that returns string lenght
 * @s: pointer to string
 * Return: Length
 */
int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}
/**
 * _strncmp - Function that returns string lenght
 * @s1: pointer to string
 * @s2: pointer to string
 * @n: number of positions to compare
 * Return: Compared string
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		else if (s1[i] == s2[i])
			i++;
	}
	return (0);
}
