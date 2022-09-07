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
 * _puts - writes a string to standard output
 * @str: string
 *
 * Return: no of chars or -1 on failure
 *
 */

ssize_t _puts(char *str)
{
	ssize_t index, length;

	index = _strlen(str);
	length = write(1, str, index);

	if (length != index)
	{
		perror("Fatal Error");
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
	unsigned int i;

	i = 0;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * _strdup - returns pointer to new memory allocate space
 * @str: string to be duplicated
 *
 * Return: a pointer to the new duplicated string
 */

char *_strdup(char *str)
{
	char *copy;

	int len, i;

	if (str == 0)
		return (NULL);

	for (len = 0; str[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}


/**
 * _strcat - concatenates two strings
 * @str1: first string
 * @str2: second string
 * Return: pointer
 */

char *_strcat(char *str1, char *str2)
{
	char *new;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (str1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; str1[len1]; len1++)
			;
	}
	if (str2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; str2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	new = malloc(newlen * sizeof(char));

	if (new == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new[i] = str1[i];
	new[i] = '/';
	for (j = 0; j < len2; j++)
		new[i + 1 + j] = str2[j];
	new[len1 + len2 + 1] = '\0';
	return (new);
}

