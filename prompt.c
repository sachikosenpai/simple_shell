#include "shell.h"

/**
 * takeinput - functiont to take input
 * @str: sting
 */

int takeinput (char* str)
{
	char* buf;
	buf = readline("\n>>> ");
	if (_strlen(buf) != 0) {
		add_history(buf);
		_strcpy(str, buf);
		return (0);
	}
	else {
		return 1;
	}
}




/**
 * _execarg - function where system is executed
 * comman: command to be executed
 * Return: void
 */

void _execarg(char** comman)
{
	pid_t pid = fork();

	if (pid == -1) {
		_putchar('failed forking child');
		_putchar('\n');
	}
	else if (pid == 0)
	{
		if (execvp(comman[0], comman) < 0)
		{
		_putchar('could not execute');
		_putchar('\n')
		}
		exit(0);
	}
	else
	{
		wait[NULL];
		return;
	}
}
