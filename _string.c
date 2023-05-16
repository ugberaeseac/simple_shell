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
/**
 * _strncmp - function to compare n bytes form string
 * pointed by s2 with s1
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * @n: number of bytes to compare
 * Return: 0 if s1 and s2 are equal
 * negative integer if s1 is less that s2
 * positive integer if s1 is greater than s2
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (s1[i] - s2[i]);
}
/**
 * _strcat - concatenates the string pointed by @src to
 * the end of the string pointed by @dest
 * @dest: String that will be append
 * @src: string that will be concatenated upon
 * Return: returns pointer to @dest
 */
char *_strcat(char *dest, char *src)
{
	char *save;

	save = dest;
	while (*save)
		save++;

	while (*src)
	{
		*save = *src;
		save++;
		src++;
	}
	*save = '\0';
	return (dest);
}
