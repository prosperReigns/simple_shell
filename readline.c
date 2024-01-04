#include "shell.h"

/**
 *getline - reads input from the user
 *
 *return: a pointer to string in memory
 */

char *getinput(void)
{
	char *buffer = NULL;
	size_t byte = 0;
	ssize_t char_read = 0;

	do
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		char_read = getline(&buffer, &byte, stdin);
		if (char_read == -1)
		{
			free(buffer);
			return (NULL);
		}

		while (char_read > 0 && (buffer[char_read -1] == '\n' || buffer[char_read - 1] == ' ' || buffer[char_read - 1] == '\t'))
		{
			buffer[--char_read] = '\0';
		}

	}while (char_read <= 1);

	return (buffer);

}
