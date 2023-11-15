#include "shell.h"

/**
<<<<<<< HEAD
 * main - simple shell fonction
 * @ac: count of arguments.
 * @argv: arguments.
 * Return: 0 always.
 */

int main(int ac, char **arg)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0, idx = 0;
	(void) ac;
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		idx++;
		cmd = tokenizer(line);
		if (!cmd)
			continue;
		if (is_builtin(cmd[0]))
			handl_builtin(cmd, argv, &status, idx);
		else
			status = _execute(cmd, argv, idx);
	}
}
