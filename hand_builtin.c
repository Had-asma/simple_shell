#include "shell.h"
/**
 * is_builtin - .....
 * @cmd: input command by user.
 * Return: integer.
 */

int is_builtin(char *cmd)
{
	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtin[i]; i++)
	{
		if (_strcmp(cmd, builtin[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - ........
 * @cmd: ........
 * @argv: ......
 * @status: .......
 * @idx: ...........
 * Return: Nothing.
 */
void handle_builtin(char **cmd, char **argv, int *status, int idx)
{
if (_strcmp(cmd[0], "exit") == 0)
exit_shell(cmd, argv, status, idx);
else if (_strcp(cmd[0], "env") == 0)
print_env(cmd, status);
}
/**
 * exit_shell - ..........
 * @cmd: ........
 * @argv:.....
 * @idx:.....
 * @status: ...........
 * Return: Nothing.
 */
void exit_shell(char **cmd, char **argv, int *status, int idx)
{
	int exit_value = (*status);
	char *index, mssg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_positive_number(cmd[1]))
		{
			exit_value = _atoi(cmd[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freecmd(cmd);
			(*status) = 2;
			return;
		}
	}
	freecmd(cmd);
	exit(exit_value);
}
/**
 * print_env - .........
 * @cmd: ........
 * @status: ..........
 * Return: Nothing.
 */
void print_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	freecmd(cmd);
	(*status) = 0;
}
