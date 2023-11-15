#include "shell.h"
/**
 * _getpath - ........
 * @cmd: input user command.
 * Return: string path of command.
 */
char *_getpath(char *cmd)
{
	char *path_env, *full_cmd, *dir
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdp(cmd));
			return (NULL);
		}
	}
	path_env = _getnev("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcp(full_cmd, dir);
			_strct(full_cmd, "/");
			_strct(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
