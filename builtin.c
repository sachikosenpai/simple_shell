#include "shell.h"

/**
 * check_builtin - to check if command is a builtin
 * @var: variable
 * Return: pointer to function or null
 */

int (*check-builtin(var_t *var))(var_t *var)
{
	unsigned int i;
	builtin_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{NULL, NULL}
	};
	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmp(var->av[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(var);
	return (check[i].f);
}



/**
 * new_exit - exit progrm
 * @var: variable
 * Return: void
 */

void new_exit(var_t *var)
{
	int stat;
	if (_strcmp(var->av[0], "exit") == 0 && var->av[1] != NULL)
	{
		stat = _atoi(var->av[1]);
		if (stat == -1)
		{
			var->stat = 2;
			print_error(var, ": illegal Number: ");
			_puts2(var->av[1]);
			_puts2("\n");
			free(var->command);
			var->command = NULL;
			return;
		}
		var->stat = stat;
	}
	free(var->buffer);
	free(var->av);
	free(var->command);
	free_env(var->env);
	exit(var->stat);
}

/**
 * _env - prints current environ
 * @var: struct of variables
 * Return: void
 */
void _env(var_t *var)
{
	unsigned int i;

	for (i = 0; var->env[i]; i++)
	{
		_puts(vars->env[i]);
		_puts("\n");
	}
	var->stat = 0;
}

/**
 * create_env - create a new environment
 * @var: pointer to strcut of vaiables
 *
 * Return: void
 */

void create_env(var_t *var)
{
	char **key;
	char *vat;


	if (var->av[1] == NULL || var->av[2] == NULL)
	{
		print_error(var, ": Incorrect number of arguments\n");
		var->stat = 2;
		return;
	}
	key = find_key(var->env, var->av[1]);
	if (key == NULL)
		add_key(var);
	else
	{
		vat = add_value(var-av[1], var->av[2]);
		if (vat == NULL)
		{
			print_error(var, NULL);
			free(var->buffer);
			free(var->command);
			free(var->av);
			free_env(var->env);
			exit(127);
		}
		free(*key);
		*key = vat;
	}
	var->stat = 0;
}
