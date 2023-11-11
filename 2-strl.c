#include "shell.h"

/**
 * _strln - length of a string
 * @c: input char
 * Return: lenght
 */

int _strln(char *c)
{
	int i = 0;

	while (*c != '\0')
	{
		c++;
		i++;
	}
	return (i);
}
