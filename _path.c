#include "shell.h"

/**
 * _getpath - get the path and check if the executable exists
 * @cmd: executable command
 *
 * Return: full path of executabe file
 */
char *_getpath(char *cmd)
{
	char **pathtoks = NULL;
	char *str = NULL;
	char *e_path = NULL, *cmd_path = NULL;

	pathtoks = _pathtokens(str);
	if (pathtoks == NULL)
		return (NULL);

	e_path = _exec_path(pathtoks, cmd);
	if (e_path == NULL)
	{
		_free_double_ptr(pathtoks);
		return (NULL);
	}

	cmd_path = _build_path(e_path, cmd);
	if (cmd_path == NULL)
	{
		_free_double_ptr(pathtoks);
		return (NULL);
	}

	_free_double_ptr(pathtoks);
	return (cmd_path);
}

/**
 * _pathtokens - tokenize the environemtal variable PATH
 * @str: PATH string
 *
 * Return: array of PATH tokens
 */
char **_pathtokens(char *str)
{
	int count = 0;
	char **tokens;
	const char *delim = "\n:";

	str = getenv("PATH");
	tokens = _parse_to_token(count, str, delim);
	if (tokens == NULL)
		return (NULL);

	return (tokens);
}


/**
 * _exec_path - get the full path of the executable command
 * @cmd: executable command
 * @tokens: array of PATH tokens
 *
 * Return: full path of executable file
 */
char *_exec_path(char **tokens, char *cmd)
{
	struct stat stat_buf;
	char *pwd = NULL, *buf = NULL;
	size_t size = 0;
	int status, i;

	pwd = getcwd(buf, size);
	if (pwd == NULL)
		return (NULL);

	if (cmd[0] == '/')
		cmd = cmd + 1;

	for (i = 0; tokens[i] != NULL; i++)
	{
		status = chdir(tokens[i]);
		if (status == -1)
		{
			perror("Error ");
			return (NULL);
		}
		status = stat(cmd, &stat_buf);
		if (status == 0)
		{
			chdir(pwd);
			free(pwd);
			return (tokens[i]);
		}
	}
	chdir(pwd);
	free(pwd);
	return (NULL);
}

