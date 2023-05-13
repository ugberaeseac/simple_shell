#include "shell.h"

/**
 * _execve - function to execute a command
 * @argv: argument vector
 * @lineptr: string entered by user
 * @counter: command counter
 * @linecmd: array of tokens
 *
 * Return: nothing
 */
void _execve(char **linecmd, char *lineptr, int counter, char **argv)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(linecmd[0], linecmd, environ) == -1)
			perror("argv[0]:");
	}
	else
		wait(&status);
}
