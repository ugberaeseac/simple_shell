#include "shell.h"
/**
 * _strcpy - copy the string pointed to by src to dest
 * Description: copy a string pointed by a pointer to another string
 * @src: pointer to string
 * @dest: pointer to string
 * Return:the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int count;

	for (count = 0; src[count] != '\0'; count++)
		dest[count] = src[count];
	dest[count] = '\0';
	return (dest);
}
/**
 * count_tokens - function that count tokens
 * @line: pointer to string
 * Return: number of tokens
 */
int count_tokens(char *line, char *delem)
{
	int counter = 0;
	char *token, *linecpy = NULL;

	linecpy = _strcpy(linecpy, line);
	token = strtok(linecpy, delem);
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, delem);
	}
	return (counter);
}
/**
 * tokenize_command - function name to tokenize the command
 * @line: pointer to string
 * @delem: pointer to string
 * Returns : array of tokens or NULL if it failed
 */
char **tokenize_command(char *line, char *delem)
{
	char **token;
	char *linecpy = NULL;
	int i = 0, cnt = 0;

	token = malloc(sizeof(char *) * strlen(line));
	if (token == NULL)
		return (NULL);
	cnt = count_tokens(line, delem);	
	linecpy = _strcpy(linecpy, line);
	token[i] = strtok(linecpy, delem);
	while (i < cnt)
	{
		token[i++] = strtok(NULL, delem);
	}
	return (token);
}
