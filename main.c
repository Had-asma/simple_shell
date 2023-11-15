#include "shell.h"

/**
<<<<<<< HEAD
 * main - simple shell fonction
 * @ac: count of arguments.
 * @argv: arguments.
 * Return: 0 always.
 */

int main (int ac, char **argv)
=======
 * main - simple shell function
 * @ac : count of arguments
 * @argv : arguments
 * Return : 0 always.
 */

int main(int ac, char **argv)
>>>>>>> 2548a2ed579ad15ce91f73006865e29718f832ff
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0, idx = 0;
	(void) ac;
	while (1)
	{
		line = read_line();
<<<<<<< HEAD
		if (line ==
=======
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
>>>>>>> 2548a2ed579ad15ce91f73006865e29718f832ff
