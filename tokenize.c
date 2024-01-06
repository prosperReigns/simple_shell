#include "shell.h"

/**
 *tokenize - splits a string
 *@input: string to split
 *
 *Return: a pointer to splited string
 */

char **tokenize(char *input)
{
	char *str;
	char **command = NULL;
	char *tokens;
	int i = 0;

	if (input == NULL)
		return (NULL);

	str = _strdup(input);

	command = malloc(sizeof(char *) * SIZE);
	if (command == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	tokens = strtok(str, " \t\n");

	while (tokens != NULL)
	{
		command[i] = _strdup(tokens);
		tokens = strtok(NULL, " \t\n");
		i++;
	}

	command[i] = NULL;
	free(str);
	str = NULL;
	free(input);

	return (command);
}

/**
 *freeMemory - frees 2d array
 *@command: 2d array
 */

void freeMemory(char **command)
{
	int i = 0;

	while (command[i] != NULL)
	{
		free(command[i]);
		i++;
	}
	free(command);
}
