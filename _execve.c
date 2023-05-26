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
	struct stat buf;
	int status, i, stat_check;
	char *cmd = NULL, *cmd_path = NULL;
	pid_t pid = fork();

	if (pid == 0)
	{
		cmd = linecmd[0];
		cmd_path = _getpath(linecmd[0]);
		if (cmd_path == NULL)
		{
			stat_check = stat(cmd, &buf);
			if (stat_check == -1)
			{
				_print_error(argv[0], counter, cmd);
				_puts(": not found");
				_putchar('\n');
				free(lineptr);
				free(cmd);
				for (i = 1; linecmd[i] != NULL; i++)
					free(linecmd[i]);
				free(linecmd);
				exit(100);
			}
			cmd_path = cmd;
		}
		linecmd[0] = cmd_path;
		if (linecmd[0] != NULL)
		{
			if (execve(linecmd[0], linecmd, environ) == -1)
				_error_execve(argv[0], counter, cmd);
		}
	}
	else
		wait(&status);
	if (WIFEXITED(status))
		statuscode = WEXITSTATUS(status);
}
