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
char *new_strtok(char *str, const char *delimiter);
char **_realloc(char **ptr, size_t *size);
char *_strdup(char *str);
char *_strcat(char *str1, char *str2);

void (*check_builtin(var_t *var))(var_t *var);
char *add_value(char *key, char *value);
char **find_key(char **env, char *key);
void add_key(var_t *var);

void new_exit(var_t *var);
void print_env(var_t *var);
void create_env(var_t *var);
void rem_env(var_t *var);
void free_env(char **env);
char **make_env(char **env);

char *convert_int(unsigned int num);
void _print_string(char *str);
ssize_t _puts(char *str);
void print_error(var_t *var, char *message);
int _atoi(char *str);

int execute_path(char *command, var_t *var);
char *find_path(char **env);
void check_path(var_t *var);
int execute_comm(var_t *var);
int check_dir(char *str);
char **tokenize(char *buffer, char *delimiter);

#endif
