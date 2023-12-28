#include "shell.h"

/**
 *_strlen - gets the lenght of a string
 *@str: string
 *return: lenght of string
 */

int _strlen(char *str){
	int i;
	int counter = 0;
	for (i = 0; str[i] != '\0'; i++)
		counter++;

	return (counter);
}

/**
 *_strcpy - copies string 
 *@dest: destination to copy string
 *@src: string to copy
 *
 *return: pointer to new string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}


