#include "shell.h"

/**
 * _echocmd - function that executes the echo command
 * @linecmd: array of command tokens
 *
 * Return: Always 0 if success otherwise -1
 */
int _echocmd(char **linecmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", linecmd, environ) == -1)
			return (-1);
		exit(1);
	}
	else if (pid < 0)
		return (-1);

	else
		wait(&status);
	if (WIFEXITED(status))
		statuscode = WEXITSTATUS(status);

	return (1);
}


/**
 * _echo - execute echo builtin
 * @linecmd: array of command tokens
 *
 * Return: void
 */
void _echo(char *lineptr)
{
	char *path, **linecmd = NULL;
	int num_token = 0;
	unsigned int  pid;
	const char *delim = "\n\t ";

	pid = getppid();
	linecmd =  _parse_to_token(num_token, lineptr, delim);
	if (linecmd == NULL)
	{
		_free_double_ptr(linecmd);
		return;
	}
	if (_strncmp(linecmd[1], "$PATH", 5) == 0)
	{
		path = getenv("PATH");
		_puts(path);
		_putchar('\n');
		free(path);
	}
	else if (_strncmp(linecmd[1], "$$", 2) == 0)
	{
		_print_number(pid);
		_putchar('\n');
		
	}
	else if (_strncmp(linecmd[1], "$?", 2) == 0)
	{
		_print_number(statuscode);
		_putchar('\n');
		
	}
	else
	{
		(_echocmd(linecmd));
	}
	_free_double_ptr(linecmd);
}
