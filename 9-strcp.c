#include "shell.h"

/**
 * *_strcp - copies this string pointed to by srd, including the terminating
 * null byte (\0), to the buffer pointed to by eest
 * @eest : char type string
 * @srd : char type string
 * Return: pointer to eest
 */

char *_strcp(char *eest, char *srd)
{
	int i;

	for (i = 0; srd[i] != '\0'; i++)
	{
		eest[i] = srd[i];
	}
	eest[i] = '\0';

	return (eest);
}
