#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 10

char *getinput(void);
char **tokenize(char *str);
int _execute(char **command, char **env);
void freeMemory(char **command);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);


#endif
