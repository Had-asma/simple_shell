#include "shell.h"

/**
 * _execut - to execute the shell commands.
 * @comand: input command by user.
 * @argv: ......
 * @idx: .........
 * Return: integer.
 */

int _execut(char **comand, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(comand[0]);
	if (!full_cmd)
	{
		print_error(argv[0], comand[0], idx);
		freecmd(comand);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, comand, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freecmd(comand);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freecmd(comand);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXISTATUS(status));
}
