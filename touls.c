#include "shell.h"
/**
 * *_itoa - fonction itoa
 * @n: integer
 * Return: ascii value
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = (n % 10) + '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdp(buffer));
}
/**
 * reverse_string - reverse strings
 * @len: integer
 * @std: value by user
 * Return: string
 */

void reverse_string(char *std, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = std[start];
		std[start] = std[end];
		std[end] = tmp;
		start++;
		end--;
	}
}

/**
 * print_err - output of error message
 * @name : name of command
 * @cmd : command
 * @idx : index of line
 * Return : string
 */

void print_err(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}

/**
 * is_positive_number - checks if a string represents a positive number
 * @std: the input string to be checked
 * Return: 1 if the string is positive number, 0 otherwise.
 */

int is_positive_number(char *std)
{
	int i;

	if (!std)
		return (0);
	for (i = 0; std[i]; i++)
	{
		if (std[i] < '0' || std[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * _atoi - converts a string to an integer
 * @std: the input string to be converted
 * Return: integer value
 */

int _atoi(char *std)
{
	int i, num = 0;

	for (i = 0; std[i]; i++)
	{
		num *= 10;
		num += (std[i] - '0');
	}

	return (num);
}
