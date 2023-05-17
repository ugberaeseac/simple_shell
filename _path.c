#include "shell.h"

/**
 * _pathtokens - tokenize the environemtal variable PATH
 * @str: environmental variable string
 *
 * Return: array of PATH tokens
 */
char **_pathtokens(char *str)
{
	int count = 0;
	char **tokens;
	const char *delim = "\n:";

	str = _getenv(PATH);
	tokens = _parse_to_token(count, str, delim);
	if (tokens == NULL)
		return (NULL);

	return (tokens);
}
