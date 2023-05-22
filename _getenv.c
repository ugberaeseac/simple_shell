#include "shell.h"

/**
 * _getenv - function that find the value of the path
 * @key: pointer to the name of the variable environment
 *
 * Return: pointer to the value of path or NULL if unsuccesfull
 */
char *_getenv(char *key)
{
	char *str, *value = NULL;
	int i = 0;
	char *env_copy;
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], key, strlen(key)) == 0)
		{
			env_copy = malloc(sizeof(char) * strlen(environ[i]));
			env_copy = strcpy(env_copy, environ[i]);
			str = strtok(env_copy, "=");
			while (str != NULL)
			{
				value = strdup(str);
				str = strtok(NULL, "=");
			}
			break;
		}
		else
			i++;
	}
	return (value);
}
