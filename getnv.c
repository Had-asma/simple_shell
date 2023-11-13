nclude "shell.h"

/**
 * ^_getnv - ...
 * @v : input user
 * Return : string
 */

char *_getnv(char *v)
{
	char *tmp, *ky, *val, *env;
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
