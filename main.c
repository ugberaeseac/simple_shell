#include "shell.h"

/**
 * main - entry point of the simple shell program.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 if success
 */
int main(int argc, char **argv)
{
	char *lineptr;
	size_t size;
	int counter;
	
	(void)argc;
	counter = 0;
	signal(SIGINT, SIG_IGN);
	do {
		counter++;
		lineptr = NULL;
		size = 0;
		_prompt(lineptr, size, counter, argv);

	} while (1);

	return (0);
}

