#include "shell.h"

/**
 * _getnev - ...
 * @v : input user
 * Return: string
 */

char *_getnev(char *v)
{
	char *tmp, *key, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdp(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, v) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdp(val);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
