#include "shell.h"

/**
 * print_msg_error - print error message 
 * @var: pointer to the struct variable
 * @message: message to print
 *
 * Return: void
 */

void print_msg_error(var_t *var, char *message)
{
	char *count;

	_print_string(var->argv[0]);
	_print_string(": ");
	count = convert_int(var->count);
	_print_string(count);
	free(count);
	_print_string(": ");
	_print_string(var->av[0]);

	if (message)
	{
		_print_string(message);
	}
	else
		perror("");
}

/**
 * _print_String - pring string to stderr
 * @str: string to print
 *
 * Return:v\ void
 */

void _print_string(char *str)
{
	ssize_t index, length;

	index = _strlen(str);
	length = write(STDERR_FILENO, str, index);
		if (length != index)
		{
			perror("Fatal Error");
			exit(1);
		}
}

/**
 * convert_int - converts an unsigned int to a string
 * @num: unsigned int to convert
 *
 * Return: pointer
 */

char *convert_int(unsigned int num)
{
	char *numstr;
	unsigned int tmp, digit;

	tmp = num;
	for (digit = 0; tmp != 0; digit++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digit + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}

	numstr[digit] = '\0';
	for (--digit; num; --digit)
	{
		numstr[digit] = (num % 10) + '0';
		num /= 10;
	}
	return (numstr);
}
	
