#include "shell.h"

/**
 * main - main function for the simple shell
 * @argc: no of arguments passed to main
 * @argv: array of arguments passed to main
 * @environment: array of env var
 *
 * Return: 0 or eexit status, or ?
 */

int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int is_pipe = 0, i;
	var_t var = {NULL, NULL, NULL, 0, NULL, 0, NULL};


	var.argv = argv;
	var.env = make_env(environment);
	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		_puts("$ ");
	while (getline(&(var.buffer), &len_buffer, stdin) != -1)
	{
		var.count++;
		var.command = tokenize(var.buffer, ";");
		for (i = 0; var.command && var.command[i] != NULL; i++)
		{
			var.av = tokenize(var.command[i], "\n\t\r");
			if (var.av && var.av[0])
				if (check_builtin(&var) == NULL)
					check_path(&var);
			free(var.av);
		}
		free(var.buffer);
		free(var.command);
		if (is_pipe == 0)
			_puts("$ ");
		var.buffer = NULL;
	}
	if (is_pipe == 0)
		_puts("\n");
	free_env(var.env);
	free(var.buffer);
	exit(var.stat);
}

