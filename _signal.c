#include "shell.h"

/**
 * _exit_d - exits the shell on getline error or Ctrl + D (EOF condition)
 * @lineptr: string input from user
 *
 * Return: void
 */
void _exit_d(char *lineptr)
{
	free(lineptr);
	exit(EXIT_SUCCESS);
}


/**
 * _signal_ignore - function that ignores ^C (SIGINT) to the process
 * @sig: integer value of signal
 *
 * Return: Nothing
 */

void _signal_ignore(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
