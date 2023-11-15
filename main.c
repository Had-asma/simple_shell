#include "shell.h"

/**
 * main - simple shell fonction
 * @ac: count of arguments.
 * @argv: arguments.
 * Return: 0 always.
 */

int main (int ac, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0, idx = 0;
	(void) ac;
	while (1)
	{
		line = read_line();
		if (line ==
