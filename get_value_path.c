#include "shell.h"
/**
 * path_value - function that find the value of the path
 * Return: pointer to the value of path or NULL if unsuccesfull
 */
char *path_value(void)
{
	char *str, *value;
	char *key = "PATH";
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], key, 4) == 0)
		{
			str = strtok(environ[i], "=");
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
