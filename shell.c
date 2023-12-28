#include "shell.h"

/**
 * mian - shell 
 *@ac: argument count
 *@av: argument vector
 *@env: environmental variable
 *
 *return: always 0
 */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	while (1)
	{
		char *input;
		char **command = NULL;
		int status = 0;

		input = getinput();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
			return (status);
		}

		command = tokenize(input);
		if(command == NULL)
		{
			free(input); input = NULL;
		}

		status = _execute(command, env);

		/*free memory*/
		freeMemory(command); command = NULL;
		free(input); input = NULL;
	}




	return (0);
}
