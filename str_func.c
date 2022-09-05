#include "shell.h"

/**
 * _strcmp - compares two strings
 * @strcmp1: first string to be compared
 * @strcmp2: second string to be compared
 * Return: 0 on success
 */

int _strcmp(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _put - writes a string to standard output
 * @str: string
 *
 * Return: no of chars or -1 on failure
 *
 */

ssize_t _puts(char *str)
{
	ssize_t index, length;
	
	index= _strlen(str);
	length = write(1, str, index);

	if (len != num)
	{
		perror("Error");
		return (-1);
	}
	return (length);
}


/**
 * _strlen - returns length of a string
 * @str: string to be measured
 * Return: length of string
 */

unsigned int _strlen(char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _atoi
