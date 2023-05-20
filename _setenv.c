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
 * @key: name of env-variable
 * @value: value of env-variable
 * @overwrite: flag 1 do change 0 do nothing
 * Return: 0 success always
 */
int _setenv(char *key, char *value, int overwrite)
{
	int i = 0;
	char *key_var;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], key, _strlen(key)) == 0)
		{
			if (overwrite == 1)
			{
				key_var = update_add_env(key, value);
				environ[i] = _strcpy(environ[i], key_var);
			}
			return (0);
		}
		i++;
	}
	key_var = update_add_env(key, value);
	environ[i] = _strcpy(environ[i], key_var);
	i++;
	environ[i] = NULL;
	return (0);
}
