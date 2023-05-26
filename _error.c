#include "shell.h"

/**
 * _putchar - function that prints a single character
 * @c: character to print
 * Return: always 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - Prints a string character by character.
 * @str: String to be printed. If the string is NULL it will print (null)
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}


/**
 * _print_number - function that prints an integer
 * to standard output
 * @n: number to be printed
 *
 * Return: count of numbers printed
 */
int _print_number(int n)
{
	int div = 1;
	int count;
	unsigned int num;

	div = 1;
	count = 0;

	num = n;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		count += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (count);
}


/**
 * _print_error - function that prints error message if the
 * executable command is not found
 * @cmd: executable command
 * @counter: command counter
 * @argv: argument vector
 *
 * Return: nothing
 */
void _print_error(char *argv, int counter, char *cmd)
{
	_puts(argv);
	_puts(": ");
	_print_number(counter);
	_puts(": ");
	_puts(cmd);
}

/**
 * _error_execve - function that prints error message if
 * execve() fails
 * @cmd: executable command
 * @counter: command counter
 * @argv: argument vector
 *
 * Return: nothing
 */
void _error_execve(char *argv, int counter, char *cmd)
{
	_print_error(argv, counter, cmd);
	_puts(": ");
	perror("");
	exit(1);
}

