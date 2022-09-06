#include "shell.h"

/**
 * make_env - make the shell env from the env passed to main
 * @env: env passed to main
 *
 * Return: pointer to new env
 */

char **make_env(char **env)
{
	char **newenv = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup(env[i]);
	newenv[i] = NULL;
	return (newenv);
}

/**
 * free_env - free shell env
 * @env: shell env
 *
 */

void free_env(char **env)
{
	unsigned int j;

	for (j = 0; env[j] != NULL; j++)
		free(env[j]);
	free(env);
}
