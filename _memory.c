#include "shell.h"

/**
 * _free_double_ptr - function that frees an array of strings
 * @str: array of strings
 *
 * Return: nothing
 */
void _free_double_ptr(char **str)
{
        int i = 0;

        while (str[i] != NULL)
        {
                free(str[i]);
                i++;
        }
        free(str);
}
