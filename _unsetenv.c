#include "shell.h"
/**
 * length_array - function that returns the number
 * elements in array of string
 * Return: integer number of elements
 */
int length_array(void)
{
	int counter = 0;

	while (environ[counter] != NULL)
	{
		counter++;
	}
	return (counter);
}
/**
 * _unsetenv - function that delete a variable name if it exist
 * if not returns with a status success
 * @lineptr: pointer to the name of the env-variable
 * Return: 0 Success always
 */
void _unsetenv(char *lineptr)
{
	char **linecmd = NULL;
	char *name = NULL;
	char *am_equal = NULL;
	const char *delim = "\t\n ";
	int i = 0, n, num_env, j, num_token = 0;

	num_token = calculate_tokens(lineptr, delim);
	if (num_token < 2)
		return;
	linecmd = _parse_to_token(num_token, lineptr, delim);
	if (linecmd == NULL)
	{
		free(linecmd);
		free(lineptr);
		return;
	}
	if (strcmp(linecmd[0], " ") == 0 || linecmd[1] == NULL)
		return;
	name = malloc(sizeof(char) * strlen(linecmd[1]));
	name = _strcpy(name, linecmd[1]);
	while (environ[i] != NULL)
	{
		am_equal = _strchr(environ[i], '=');
		if (am_equal != NULL)
		{
			n = strlen(environ[i]) - strlen(am_equal);
			if ((strncmp(environ[i], name, n)) == 0)
			{
				num_env = length_array();
				for (j = i; j < num_env - 1; j++)
				{
					environ[j] = environ[j + 1];
				}
				num_env--;
				environ[j - 1] = NULL;
			}
		}
		i++;
	}
}
