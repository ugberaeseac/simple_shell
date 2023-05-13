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
 * _strlen - function name
 * Description: calculate the length of a string
 * @s: pointer to string
 * Return: integer length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
/**
 * _strdup - function name
 * Description: a function that returns a pointer to a
 * newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: pointer to string
 * Return: returns NULL if str is NULL or a pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int i;

	if (str == NULL)
		return (NULL);
	duplicate = (char *)malloc(sizeof(char) * (_strlen(str) + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		duplicate[i] = str[i];
	}
	duplicate[i] = '\0';
	return (duplicate);
}
