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

#endif
