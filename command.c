#include "shell.h"

/**
 * get_full_path - gets a command full path
 * @cmd: command to get
 * @env: environment variables
 *
 * Return: a pointer to a new string
 */

char *get_full_path(char *cmd, char **env)
{
	char *path = _getenv("PATH", env);
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		char *full_path =  join_path(dir, '/', cmd);

		if (path_exist(full_path) == 0)
		{
			free(path);
			return (full_path);
		}

		dir = strtok(NULL, ":");
	}
	free(path);
	return (0);
}

/**
 * join_path - create a full command path
 * @bin_dir: directories in environment variable
 * @delim: separator
 * @cmd: user command
 *
 * Return: a pointer to a new string
 */

char *join_path(char *bin_dir, char delim, char *cmd)
{
	int len, len1, i, j;
	char *full_path;

	len = _strlen(bin_dir);
	len1 = _strlen(cmd);

	full_path = malloc(sizeof(char) * (len + len1 + 3));
	if (!full_path)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (bin_dir[i] != '\0')
	{
		full_path[i] = bin_dir[i];
		i++;
	}
	full_path[i] = delim;
	i++;

	j = 0;
	while (cmd[j] != '\0')
	{
		full_path[i] = cmd[j];
		j++;
		i++;
	}

	full_path[i] = '\0';

	if (path_exist(full_path) == 0)
		return (full_path);

	free(full_path);
	return (NULL);
}

/**
 * path_exist - check if a flie exist
 * @name: filename
 *
 * Return: 0 on success
 */

int path_exist(char *name)
{
	struct stat st;

	if (stat(name, &st) == 0)
		return (0);

	return (1);
}
