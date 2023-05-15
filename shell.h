#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#define PROMPT "$ "

extern char **environ;

char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *s);
char *_strdup(char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
void _prompt(char *lineptr, size_t size, int counter, char **argv);
void _exit_d(char *lineptr);
void _execve(char **linecmd, char *lineptr, int counter, char **argv);
int calculate_tokens(char *lineptr, const char *delim);
char **_parse_to_token(int num_token, char *lineptr, const char *delim);
char *_getenv(char *key);

#endif
