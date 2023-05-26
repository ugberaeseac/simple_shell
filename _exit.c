#include "shell.h"

/**
 * _atoi - function that converts a string to integer
 * @str: string to convert
 *
 * Return: integer value of converted string
 */
int _atoi(char *str)
{
	int i;
	unsigned int int_num = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			int_num = int_num * 10 + (str[i] - '0');

		if (str[i] > '9' || str[i] < '0')
			return (-1);
	}
	return (int_num);
}

/**
 * _exits - function that exits the simple shell
 * @lineptr: command line input string from user
 * @counter: counter
 * @argv: argument vector
 *
 * Return: exit shell if success, -1 if error
 */
int _exits(char *lineptr, int counter, char **argv)
{
	int status = 0;
	char **exit_token;
	int token_count = 0;
	const char *delim = "\n\t ";

	exit_token = _parse_to_token(token_count, lineptr, delim);
	if (exit_token == NULL)
	{
		free(lineptr);
		_free_double_ptr(exit_token);
		return (-1);
	}

	if (exit_token[1] != NULL)
	{
		status = _atoi(exit_token[1]);
		statuscode = status;
	}

	if (status < 0)
	{
		_print_error(argv[0], counter, exit_token[0]);
		_puts(": Illegal number: ");
		_puts(exit_token[1]);
		_putchar('\n');
		_free_double_ptr(exit_token);
		return (2);
	}

	_free_double_ptr(exit_token);
	free(lineptr);
	exit(statuscode);
}
