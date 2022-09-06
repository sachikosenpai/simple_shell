#include "shell.h"

/**
 * add_key - create a new environment
 * @var: pointer to the struct of variables
 *
 * Return: void
 */

void add_key(var_t *var)
{
	unsigned int i;
	char **new;

	for (i = 0; var->env[i] != NULL; i++)
		;
	new = malloc(sizeof(char *) * (i + 2));
	if (new == NULL)
	{
		print_error(var, NULL);
		var->stat = 127;
		new_exit(var);
	}
	for (i = 0; var->env[i] != NULL; i++)
		new[i] = var->env[i];
	new[i] = add_value(var->av[i], var->av[2]);
	if (new[i] == NULL)
	{
		print_error(var, NULL);
		free(var->buffer);
		free(var->command);
		free(var->av);
		free_env(var->env);
		free(new);
		exit(127);
	}
	new[i + 1] = NULL;
	free(var->env);
	var->env = new;
}

/**
 * find_key - finds an environment variable
 * @env: array of env variables
 * @key: env variables to find
 *
 * Return: pointer to address of env variable
 */

char **find_key(char **env, char *key)
{
	unsigned int i, j, len;

	len = _strlen(key);
	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
			if (key[j] != env[i][j])
				break;
		if (j == len && env[i][j] == '=')
			return (&env[i]);
	}
	return (NULL);
}


/**
 * add_value - create a new environment variable string
 * @key: var name
 * @value: var value
 *
 * Return: pointer to new str
 */

char *add_value(char *key, char *value)
{
	unsigned int len1, len2, i, j;
	char *newv;

	len1 = _strlen(key);
	len2 = _strlen(value);
	newv = malloc(sizeof(char) * (len1 + len2 + 2));
	if (newv == NULL)
		return (NULL);
	for (i = 0; key[i] != '\0'; i++)
		newv[i] = key[i];
	newv[i] = '=';
	for (j = 0; value[j] != '\0'; j++)
		newv[i + 1 + j] = value[j];
	newv[i + 1 + j] = '\0';
	return (newv);
}

/**
 * _atoi - convert string to integer
 * @str: str to convert
 *
 * Return: int value or 0 if it fails
 *
 */

int _atoi(char *str)
{
	unsigned int i, digits;
	int num = 0, num_t;

	num_t = INT_MAX;
	for (digits = 0; num_t != 0; digits++)
		num_t /= 10;
	for (i = 0; str[i] != '\0' && i < digits; i++)
	{
		num *= 10;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if ((i == digits - 1) && (str[i] - '0' > INT_MAX % 10))
			return (-1);
		num += str[i] = '0';
		if ((i == digits - 2) && (str[i + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (i > digits)
		return (-1);
	return (num);
}
