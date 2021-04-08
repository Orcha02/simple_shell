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
/**
 * str_concat - concatenate to strings
 *@s1: string
 *@s2: string
 * Return: the string concat
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, k, l;
	char *p;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	for (i = 0; *(s1 + i) != '\0'; i++)
	{}
	for (j = 0 ; *(s2 + j) != '\0' ; j++)
	{}
	p = malloc(sizeof(char) * (i + j + 1));
	if (p == NULL)
	{
		return (NULL);
	}
	for (k = 0; k < i; k++)
	{
		*(p + k) = *(s1 + k);
	}
	for (l = 0; l < j; l++)
	{
		*(p + (i + l)) = *(s2 + l);
	}
	p[i + j] = '\0';
	return (p);
}
