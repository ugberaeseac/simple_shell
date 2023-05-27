#include "shell.h"

/**
 * _built_in - function that checks for builtin functions
 * @lineptr: string entered by user
 * @linecmd: array of tokens
 *
 * Return: 0 if builtin found, else -1
 */
int _built_in(char **linecmd, char *lineptr)
{
	void (*func_ptr)(char *);

	func_ptr = _check_builtin(linecmd[0]);
	if (func_ptr == NULL)
		return (-1);

	if (_strcmp("exit", linecmd[0]) == 0)
		_free_double_ptr(linecmd);

	func_ptr(lineptr);
	return (0);
}



/**
 * _check_builtin - function that returns the right builtin function
 * @func: builtin function
 *
 * Return: pointer to the function
 */
void (*_check_builtin(char *func))(char *str)
{
	int i;

	built_t built_cmds[] = {
		{"cd", _cd},
		{"env", _env},
		{"exit", _exit_},
		{"echo", _echo},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; built_cmds[i].built_in != NULL; i++)
	{
		if (_strcmp(built_cmds[i].built_in, func) == 0)
		{
			return (built_cmds[i].fptr);
		}
	}
	return (NULL);
}

/**
 * _env - function that prints the environmental variables
 * @lineptr: parameter
 *
 * Return: void
 */
void _env(char *lineptr)
{
	int i;
	int j;

	(void)lineptr;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}




/**
 * _cd - function that changes the directory to the paramater passed.
 * @lineptr: parameter
 *
 * Return: void
 */
void _cd(char *lineptr)
{
	char **linecmd = NULL;
	int num_token = 0;
	const char *delim = "\n\t ";

	linecmd = _parse_to_token(num_token, lineptr, delim);
	if (linecmd[0] == NULL)
	{
		free(linecmd);
		free(lineptr);
		return;
	}
	if (linecmd[1]  == NULL)
		cd_home();
	else if (_strcmp(linecmd[1], ".") == 0)
		cd_cwd();
	else if (_strcmp(linecmd[1], "-") == 0)
		cd_toggle();
	else
		cd_abspath(linecmd[1]);
	_free_double_ptr(linecmd);
}


/**
 * cd_setenv - function that sets PWD env variable
 * to the current working directory
 * @key: name of env-variable
 * @value: value of env-variable
 * @overwrite: flag 1 do change 0 do nothing
 *
 * Return: 0 success always
 */
int cd_setenv(char *key, char *value, int overwrite)
{
	int i = 0;
	char *key_var = NULL;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], key, _strlen(key)) == 0)
		{
			if (overwrite == 1)
			{
				key_var = update_add_env(key, value);
				environ[i] = malloc(sizeof(char) * _strlen(key_var) + 1);
				_strcpy(environ[i], key_var);
				free(key_var);
			}
			return (0);
		}
		i++;
	}
	key_var = update_add_env(key, value);
	environ[i] = malloc(sizeof(char) * _strlen(key_var) + 1);
	_strcpy(environ[i], key_var);
	i++;
	environ[i] = '\0';

	free(key_var);
	return (0);
}
