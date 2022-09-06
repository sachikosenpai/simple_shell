#include "shell.h"


/**
 * execute_path - executes a command in path
 * @command: full path to the command
 * @var: pointer to the struct
 *
 * Return: 0 on succes
 */

int execute_path(char *command, var_t *var)
{
	pid_t child_pid;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			print_error(var, NULL);
		if (child_pid == 0)
		{
			if (execve(command, var->av, var->env) == -1)
				print_error(var, NULL);
		}
		else
		{
			wait(&var->stat);
			if (WIFEXITED(var->stat))
				var->stat = WEXITSTATUS(var->stat);
			else if (WIFSIGNALED(var->stat) && WTERMSIG(var->stat) == SIGINT)
				var->stat = 130;
			return (0);
		}
		var->stat = 127;
		return (1);
	}
	else
	{
		print_error(var, ": Permission denied\n");
		var->stat = 126;
	}
	return (0);
}


/**
 * find_path - find the path variable
 * @env: array of env variables
 *
 * Return: pointer to the nodes that contains path and NULL if fails
 */

char *find_path(char **env)
{
	char *path = "PATH=";
	unsigned int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;

	}
	return (env[i]);

}

/**
 * check_path - confirms if the command is in the path
 * @var: variable
 *
 * Return: void
 */

void check_path(var_t *var)
{
	char *path, *path_dup = NULL, *check = NULL;
	unsigned int i = 0, r = 0;
	char **path_tokens;
	struct stat buf;

	if (check_dir(var->av[0]))
		r = execute_comm(var);
	else
	{
		path = find_path(var->env);
		if (path != NULL)
		{
			path_dup = _strdup(path + 5);
			path_tokens = tokenize(path_dup, ":");
			for (i = 0; path_tokens && path_tokens[i]; i++, free(check))
			{
				check = _strcat(path_tokens[i], var->av[0]);
				if (stat(check, &buf) == 0)
				{
					r = execute_path(check, var);
					free(check);
					break;
				}
			}
			free(path_dup);
			if (path_tokens == NULL)
			{
				var->stat = 127;
				new_exit(var);
			}
		}
		if (path == NULL || path_tokens[i] == NULL)
		{
			print_error(var, ": not found\n");
			var->stat = 127;
		}
		free(path_tokens);
	}
	if (r == 1)
		new_exit(var);
}

/**
 * execute_comm - execute command in the working dir
 * @var: pointer
 *
 * Return: 0 on succes 1 on failure
 */

int execute_comm(var_t *var)
{
	pid_t child_pid;
	struct stat buf;

	if (stat(var->av[0], &buf) == 0)
	{
		if (access(var->av[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				print_error(var, NULL);
			if (child_pid == 0)
			{
				if (execve(var->av[0], var->av, var->env) == -1)
					print_error(var, NULL);
			}
		else
		{
			wait(&var->stat);
			if (WIFEXITED(var->stat))
				var->stat = WEXITSTATUS(var->stat);
			else if (WIFSIGNALED(var->stat) && WTERMSIG(var->stat) == SIGINT)
				var->stat = 130;
			return (0);
		}
		var->stat = 127;
		return (1);
	}
	else
	{
		print_error(var, ":Permission denied\n");
		var->stat = 126;
	}
	return (0);
	}
	print_error(var, ": not found\n");
	var->stat = 127;
	return (0);
}

/**
 * check_dir - checks if the command is part
 * @str: command
 *
 * Return: 1 on succes 0 on failure
 */

int check_dir(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}
