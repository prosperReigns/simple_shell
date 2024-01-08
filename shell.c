#include "shell.h"

/**
 *main - shell
 *@ac: argument count
 *@av: argument vector
 *@env: environmental variable
 *
 *Return: always 0
 */

int main(__attribute__((unused)) int ac, char **av, char **env)
{
	while (1)
	{
		char *input;
		char **command = NULL;
		int status;

		input = getinput();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO) == 0)
				break;
			continue;
		}

		command = tokenize(input);
		if (command == NULL)
		{
			free(input);
		}

		if (is_builtin(command[0]) == 0)
			handle_builtin(command, env);
		else
			status = _execute(av, command, env);
		(void)status;

		if (isatty(STDIN_FILENO) == 0)
			break;
	}




	return (0);
}
