#include "headers.h"

/**
 * error_printing - Entry point
 *@av: command
 *@count: tokens
 *@command: char string
 * Return: Always 0 (Success)
 */
void error_printing(char *av, int count, char *command)
{
	print_string(av, 1);
	print_string(": ", 1);
	print_number(count);
	print_string(": ", 1);
	print_string(command, 1);
}
/**
 * exec_error - Entry point
 *@av: command[0]
 *@count: count tokens
 *@tmp_command: command
 * Return: void
 */
void exec_error(char *av, int count, char *tmp_command)
{
	error_printing(av, count, tmp_command);
	print_string(": ", 1);
	perror("");
	exit(1);
}
/**
 * print_string - Entry point
 *@str: char string
 *@new_line: string
 * Return: void
 */
void print_string(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}
/**
 * print_number - Entry point
 *@n: int
 * Return: length
 */
int print_number(int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
/**
 * _write - Entry point
 *@c: character
 * Return: Always 0 (Success)
 */
int _write(char c)
{
	return (write(1, &c, 1));
}
