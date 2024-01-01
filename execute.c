#include "shell.h"

/**
 *_execute - executes a command
 *@command: an array of commands
 *@env: an array of environmental variables
 *
 *return: status of execution
 */

int _execute(char **command, char **env)
{
	pid_t child;
	int status;
	char *full_cmd;

	full_cmd = get_full_path(command[0], env);
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
		free(full_cmd);
		waitpid(child, &status, 0);
	}
	return (status);
}
