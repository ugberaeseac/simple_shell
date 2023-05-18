#include "shell.h"

/**
 * _build_path - builds the executable path of the command
 * @e_path: path of the executable command
 * @cmd: executable command
 *
 * Return: full executable path of the command
 */
char *_build_path(char *e_path, char *cmd)
{
	int path_length = 0;
	char *path = NULL;

	if (e_path == NULL || cmd == NULL)
		return (NULL);

	path_length = (_strlen(e_path) + _strlen(cmd) + 2);
	path = malloc(sizeof(char) * path_length);
	if (path == NULL)
		return (NULL);

	_strcpy(path, e_path);
	_strcat(path, "/");
	_strcat(path, cmd);
	_strcat(path, "\0");

	return (path);
}
