#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct variable - variables
 * @av: command line for arguments
 * @buffer: buffer command
 * @env: environ variables
 * @count: counts of command entered
 * @argv: argument at opening of shell
 * @stat: exit status
 * @command: commandds to execute
 */
typedef struct variable
{
	char **av;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int stat;
	char **command;
} var_t;

/**
 * struct builtin - struct for the builtin function
 * @name: builtin command
 * @f: function for builtin
 */

typedef struct builtin
{
	char *name;
	void (*f)(var_t *);
} builtin_t;

int _strcmp(char *strcmp1, char *strcmp2);
unsigned int _strlen(char *str); 

void (*check_for_builtin(var_t *vars))(var_t *var);

void new_exit(var_t *var);
void _env(var_t *var);
void create_env(var_t *var);

char *convert_int(unsigned int num);
void _print_string(char *str);
ssize_t _puts(char *str);

#endif
