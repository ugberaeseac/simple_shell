#include "shell.h"
/**
 * _getenv - function that find the value of the path
 * @key: pointer to the name of the variable environment
 * Return: pointer to the value of path or NULL if unsuccesfull
 */
char *_getenv(char *key)
{
	char *str, *value;
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], key, _strlen(key)) == 0)
		{
			str = strtok(environ[i], "=");
			while (str != NULL)
			{
				value = _strdup(str);
				str = strtok(NULL, "=");
			}
			break;
		}
		else
			i++;
	}
	return (value);
}
