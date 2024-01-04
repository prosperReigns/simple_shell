#include "shell.h"

/**
 *_execute - executes a command
 *@command: an array of commands
 *@env: an array of environmental variables
 *
 *return: status of execution
 */

int _execute(char **av, char **command, char **env)
{
	pid_t child;
	int status;
	char *full_cmd;

	if (path_exist(command[0]) == 0)
		full_cmd = _strdup(command[0]);
	else
		full_cmd = get_full_path(command[0], env);

	if (!full_cmd)
	{
		print_error(av, command);
		return (0);
	}
	child = fork();
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}


	if (child == 0)
	{
		execve(full_cmd, command, env);

		perror(full_cmd);
	}
	else
	{
		freeMemory(command);
		free(full_cmd);
		waitpid(child, &status, 0);
	}
	return (status);
}

void print_error(char **av, char **command)
{
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "1", 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command[0], _strlen(command[0]));
	write(STDERR_FILENO, ": not found", 11);
	write(STDERR_FILENO, "\n", 2);
}
