#include "shell.h"
/**
 * _strct - concatenate two strings.
 * @eest: string to destiny
 * @srd: string to source
 * Return: concatenate string
 */

char *_strct(char *eest, char *srd)
{
	int i = 0, lenght = 0;

	while (*(eest + lenght) != '\0')
		lenght++;
	for (i = 0; *(srd + i) != '\0'; i++)
	{
		*(eest + lenght) = *(srd + i);
		lenght++;
	}
	*(eest + lenght) = '\0';

	return (eest);
}
