#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SIZE 10

char *getinput(void);
char **tokenize(char *str);
int _execute(char **av, char **command, char **env);
void print_error(char **av, char **command);
void freeMemory(char **command);
char *_getenv(char *path, char **env);
char *get_full_path(char *cmd, char **env);
char *join_path(char *binary_dir, char delim, char *cmnd);
int path_exist(char *name);
int is_builtin(char *cmd);
void handle_builtin(char **cmd, char **env);
void logout(void);
void print_env(char **env);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str, char *str1);


#endif
