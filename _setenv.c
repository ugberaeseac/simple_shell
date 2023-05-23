#include "shell.h"

/**
 * update_add_env - function that add an env variable
 * @key: name of the env variable
 * @value: value of the env variable
 * Return: a pointer to the allocated space for the env if Success
 * and NULL otherwise
 */
char *update_add_env(char *key, char *value)
{
	char *key_var;

	key_var = malloc(sizeof(char) * _strlen(key) + _strlen(value) + 2);
	if (key_var == NULL)
		return (NULL);
	key_var = _strcpy(key_var, key);
	key_var = _strcat(key_var, "=");
	key_var = _strcat(key_var, value);
	return (key_var);
}


/**
 * _setenv - function that change the env variable if overwrite = 1
 * no change if overwrite = 0
 * @lineptr: name of env-variable
 *
 * Return: void
 */
void _setenv(char *lineptr)
{
	char *key = NULL, *value = NULL;
	char *key_var = NULL;
	char **linecmd = NULL;
	int num_token = 0, i = 0;
	const char *delim = "\n\t ";

	linecmd = _parse_to_token(num_token, lineptr, delim);
	if (!(linecmd))
	{
		_puts("Too few arguments\n");
		_free_double_ptr(linecmd);
		free(lineptr);
		return;
	}
	key = _strdup(linecmd[1]);
	value = _strdup(linecmd[2]);

	while (environ[i] != NULL)
        {
                if (_strncmp(environ[i], key, _strlen(key)) == 0)
                {
                        key_var = update_add_env(key, value);
                        environ[i] = _strcpy(environ[i], key_var);
                        return;
                }
                i++;
        }
	
	key_var = update_add_env(key, value);
	if (key_var == NULL)
		return;
	environ[i] = _strcpy(environ[i], key_var);
	i++;
	environ[i] = NULL;

	free(key);
	free(value);
	_free_doubnle_ptr(linecmd);
	free(lineptr);
}
