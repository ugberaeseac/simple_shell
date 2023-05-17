#include "shell.h"

/**
 * _prompt - display a prompt, take and pass a command for execution
 * @argv: argument vector
 * @lineptr: string entered by user
 * @counter: command counter
 * @size: buffer size
 *
 * Return: nothing
 */
void _prompt(char *lineptr, size_t size, int counter, char **argv)
{
	int i, builtin_stat;
	ssize_t nread;
	int num_token;
	char **linecmd;
	const char *delim = "\n\t ";
	
	num_token = 0;
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		fflush(stdout);
	}
	nread = getline(&lineptr, &size, stdin);
	if (nread != -1)
	{
		linecmd = _parse_to_token(num_token, lineptr, delim);
		if (linecmd[0] == NULL)
		{
			free(linecmd);
			free(lineptr);
			return;
		}
		builtin_stat = _built_in(linecmd, lineptr);
		if (builtin_stat == -1)
			_execve(linecmd, lineptr, counter, argv);
		for (i = 0; linecmd[i] != NULL; i++)
			free(linecmd[i]);
		free(linecmd);
		free(lineptr);
	}
	else
		_exit_d(lineptr);
}
