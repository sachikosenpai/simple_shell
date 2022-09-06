#include "shell.h"

/**
 * check_char - check if a char matches str
 * @c: character to check
 * @str: str to check
 *
 * Return: 1 if match, 0 if not
 */

unsigned int check_char(char c, const char *str)
{
	unsigned int j;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (c == str[j])
			return (1);
	}
	return (0);
}

/**
 * new_strtok - custom strtok
 * @str: string to tokenize
 * @delimiter: delimiter to tokenize against
 *
 * Return: pointer to token or null
 */

char *new_strtok(char *str, const char *delimiter)
{
	static char *token_start;
	static char *next_token;
	unsigned int i;

	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_char(next_token[i], delimiter) == 0)
			break;
	}
	if (next_token[i] == '\0' || next_token[i] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + i;
	next_token = token_start;

	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_char(next_token[i], delimiter) == 1)
			break;
	}
	if (next_token[i] == '\0')
		next_token = NULL;
	else
	{
		next_token[i] = '\0';
		next_token = next_token + i + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}

