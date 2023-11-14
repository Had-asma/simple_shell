#include "shell.h"
/**
 * is_biltin - .....
 * cmd: ....
 * Return: integer.
 */

int is_biltin(char *cmd)
{
	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for ( i = 0; builtin[i]; i++)
	{
		if (_strcmp(cmd, builtin[i] == 0)
				return (1);
	}
	return (0);
}

/**
 * handl_builtin - ........
 * @cmd: ........
 * @argv: ......
 * @status: .......
 * @idx: ...........
 * Return: Nothing.
 */
