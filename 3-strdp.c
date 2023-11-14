#include "shell.h"

/**
 * _strdp - duplicate
 * @str : the string to duplicate
 * Return : duplicate string.
 */

char *_strdp(const char *str)
{
	char *ptr;
	int i, ln = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		ln++;
		str++;
	}
	str = str - ln;
	ptr = malloc(sizeof(char) * (ln + 1));

	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= ln; i++)
		ptr[i] = str[i];
	return (ptr);
}
