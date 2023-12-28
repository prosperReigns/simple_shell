#include "shell.h"

/**
 *tokenize - splits a string
 *@input: string to split
 *
 *return: a pointer to splited string
 */

char** tokenize(char *input)
{
	char *str;
	char **command = NULL;
	char *tokens;
	int len = 0, i = 0, token_len = 0;

	if (input == NULL){
		return NULL;
	}

	len = _strlen(input);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
	{
		exit(EXIT_FAILURE);
	}

	_strcpy(str, input);

	command = malloc(sizeof(char *) * SIZE);
	if (command == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	tokens = strtok(str, " \t\n");
	token_len = _strlen(tokens);

	while (tokens != NULL)
	{
		command[i] = malloc(sizeof(char) * token_len + 1);
		if (command[i] == NULL)
		{
			free(str); str = NULL;
			free(command[i]); 
			free(command); command = NULL;
			exit(EXIT_FAILURE);
		}
		_strcpy(command[i], tokens);

		tokens = strtok(NULL, " \t\n");
		i++;
	}

	command[i] = NULL;
	free(str); str = NULL;

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
