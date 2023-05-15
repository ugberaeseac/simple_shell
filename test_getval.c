#include "shell.h"
/**
 * main - test for function to get path
 * @argc: number of commands
 * @argv: array of commands
 * Return: 0 success always
 */
int main(int argc, char **argv)
{
        char *path_v;

        (void)argc;
        (void)argv;

        path_v = path_value();
        printf("%s\n", path_v);
        return (0);
}
