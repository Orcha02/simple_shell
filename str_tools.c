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
	char *array;
	int i = 0, l1 = 0, l2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[l1] != '\0')
	{
		l1++;
	}

	while (s2[l2] != '\0')
	{
		l2++;
	}

	array = malloc(sizeof(char) * (l1 + l2 + 1));
	if (array == NULL)
		return (NULL);

	while (*s1)
	{
		array[i] = *s1;
		i++;
		s1++;
	}

	while (*s2)
	{
		array[i] = *s2;
		i++;
		s2++;
	}
	array[i] = '\0';
	return (array);
}
/**
 * _strdup - string duplicate with malloc
 *@str: string
 * Return: the string
 */
char *_strdup(char *str)
{
	char *copy;
	int i, largo = 0;

	if (!str)
		return (NULL);

	while (str[largo] != '\0')
	{
		largo++;
	}

	copy = malloc(sizeof(char) * (largo + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= largo; i++)
		copy[i] = str[i];

	return (copy);
}
