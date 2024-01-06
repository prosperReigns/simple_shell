#include "shell.h"

/**
 * _getenv - gets environment variable
 * @path: variable to get
 * @env: environmental variable
 *
 * Return: a pointer to a string
 */

char *_getenv(char *path, char **env)
{
	int i = 0;
	char *variable;
	char *dir;

	variable = _strdup(env[i]);
	while (variable != NULL)
	{
		char *key = strtok(variable, "=");
		char *value = strtok(NULL, "=");

		if (_strcmp(key, path) == 0)
		{
			dir = _strdup(value);
			free(variable);
			return (dir);
		}

		i++;
		free(variable);
		variable = _strdup(env[i]);
	}

	free(variable);
	return (NULL);
}
