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

	child = fork();
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}


	if (child == 0)
	{
		execve(command[0], command, env);

		perror(command[0]);
	}
	else
	{
		waitpid(child, &status, 0);
	}
	return (status);
}
