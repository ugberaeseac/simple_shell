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
	exit(EXIT_FAILURE);
}
