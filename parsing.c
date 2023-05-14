#include "shell.h"
/**
 * calculate_tokens - function to calculate token command
 * @lineptr: pointer to string
 * Return: number of tokens
 */
 int calculate_tokens(char *lineptr, char *delim)
 {
    int counter = 0;
    char *token, *line_copy;

    line_copy = _strcpy(line_copy, lineptr);
    token = strtok(line_copy, delim);
    while (token != NULL)
    {
        counter++;
        token = strtok(line_copy, delim);
    }
    return (counter);
 }
/**
 * _parse_to_token - tokenize the input (command)
 * @num_token: number of token returned by the function calculate_token
 * @lineptr: pointer to the command to be tokenized
 * @delim: the delimiter between tokens
 * Return: array of tokens to be passed to the execve function
 */
char **_parse_to_token(int num_token, char *lineptr, delim)
{

}
