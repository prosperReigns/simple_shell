#include "shell.h"

/**
 * is_builtin - checks if a command is builtin or not
 * @cmd: command user entered
 *
 * Return: 0 on success
 */

int is_builtin(char *cmd)
{
	char *builtin_command[] = {"exit", "env", "cd", NULL};
	int i = 0;

	while (builtin_command[i] != NULL)
	{
		if (_strcmp(cmd, builtin_command[i]) == 0)
			return (0);

		i++;
	}
	return (1);

}

/**
 * handle_builtin - handles biultin commands
 * @cmd: commands entered by user
 * @env: environment variable
 *
 */

void handle_builtin(char **cmd, char **env)
{
	if (_strcmp(cmd[0], "exit") == 0)
	{
		freeMemory(cmd);
		logout();
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		print_env(env);
	}

	freeMemory(cmd);

}

/**
 * logout - exits the shell
 *
 */

void logout(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * print_env - prints environment variables
 * @env: environment variable
 *
 */

void print_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
