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

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * return: a pointer to a new string
 */

char *_strdup(char *str)
{
	int len = _strlen(str);
	char *string = malloc(sizeof(char) * len + 1);

	int i = 0;
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}

	string[i] = '\0';

	return(string);

}

/**
 * _strcmp - compares two string for equality
 * @str: string to cmpare
 * @str1: string to compare
 *
 * return: 0 on success
 */

int _strcmp(char *str, char *str1)
{
	int i;

	i = 0;
	while (str[i] == str1[i] && str[i] != '\0' && str1[i] != '\0')
		i++;

	return (str[i] - str1[i]);

}

