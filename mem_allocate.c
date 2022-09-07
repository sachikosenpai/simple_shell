#include "shell.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to old array
 * @size: pointer to no of elements in old array
 *
 * Return: pointer to new array
 */

char **_realloc(char **ptr, size_t *size)
{
	char **new_a;
	size_t index;

	new_a = malloc(sizeof(char *) * ((*size) + 10));

	if (new_a == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (index = 0; index < (*size); index++)
	{
		new_a[index] = ptr[index];
	}
	*size += 10;
	free(ptr);
	return (new_a);
}

