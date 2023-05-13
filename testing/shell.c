#include "shell.h"
/**
 * main - Entry point
 * @argc: number of commands
 * @argv: array that holds the argumens
 * Return: returns 0 on success and 1 otherwise
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char **token, *line = NULL;
	ssize_t r_check;
	size_t size;
	int i = 0;
	char *delem = " ";

	while (1)
	{
		write(STDIN_FILENO, &PROMPT, strlen(PROMPT));
		r_check = getline(&line, &size, stdin);
		if (r_check == -1)
			return (-1);
		token = tokenize_command(line, delem);
		printf("%s\n", token[i]);
	}
	return (0);
}
