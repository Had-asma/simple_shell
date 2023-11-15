#include "shell.h"

/**
 * _execut - to execute the shell commands.
 * @cmd: input command by user.
 * @argv: ......
 * @idx: .........
 * Return: integer.
 */

int _execut(char **cmd, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(cmd[0]);
	if (!full_cmd)
	{
		print_error(argv[0], cmd[0], idx);
		freecmd(cmd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freecmd(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freecmd(cmd);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXISTATUS(status));
}
