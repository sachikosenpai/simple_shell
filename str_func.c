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

