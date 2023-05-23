#include "shell.h"
/**
 * _strcmp - function that compare two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * Return: 0 if s1 and s2 are equal
 * negative integer if s1 is less than s2
 * positive integer if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/**
 * _strchr - a function that locates a character in a string.
 * @s: pointer to string
 * @c: character to be located
 * Return: returns the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
