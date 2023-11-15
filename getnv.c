#include "shell.h"

/**
 * _getenv - ...
 * @v : input user
 * Return: string
 */

char *_getenv(char *v)
{
	char *tmp, *key, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdp(environ[i]);
		ky = strtok(tmp, "=");
		if (_strcmp(ky, v) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdp(val);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
