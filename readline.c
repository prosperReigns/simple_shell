#include "shell.h"

/**
 *getinput - reads input from the user
 *
 *Return: a pointer to string in memory
 */

char *getinput(void)
{
	char *buffer = NULL;
	size_t byte = 0;
	ssize_t char_read = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	char_read = getline(&buffer, &byte, stdin);
	if (char_read <= 1 || trim(buffer) == 0)
	{
		free(buffer);
		return (NULL);
	}

	return (buffer);

}

/**
 * trim - removes whitespaces
 * @buffer: string read from user
 *
 * Return: lenght of buffer
 */

int trim(char *buffer)
{
	int i;

	i = _strlen(buffer) - 1;

	while (i > 0 && (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t'))
	{
		buffer[i] = '\0';
		i--;
	}

	return (i);
}
