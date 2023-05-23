#include "shell.h"

/**
 * _getline - function that reads an entire line from stream
 * @lineptr: pointer to the string read
 * @size: allocated buffer size
 * @stream: input
 *
 * Return: number of characters read
 */
ssize_t _getline(char **lineptr, ssize_t size, FILE *stream)
{

	char buf[1024];
	ssize_t n_read = 0, i = 0;
	ssize_t flag = 0, flag1 = 0;

	fflush(stream);

	while (flag == 0 && (n_read = read(STDIN_FILENO, buf, 1023)))
	{
		if (n_read == -1)
			return (-1);

		buf[n_read] = '\0';

		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				flag = 1;
			i++;
		}

		if (flag1 == 0)
		{
			*lineptr = malloc(sizeof(char) * n_read);
			*lineptr = _strcpy(*lineptr, buf);
			size = n_read;
			flag1 = 1;
		}
		else
		{
			size += n_read;
			*lineptr = _strcat(*lineptr, buf);
		}

	}
	return (size);
}
