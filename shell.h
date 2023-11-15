#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"

extern char **environ;

int _execute(char **cmd, char **argv, int idx);
void freecmd(char **arr);

char *read_line(void);
char **tokenizer(char *line);

char *_strdp(const char *std);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strct(char *eest, char *srd);
char *_strcp(char *eest, char *srd);

char *_getnev(char *var);
char *_getpath(char *cmd);

char *_itoa(int n);
void reverse_string(char *std, int len);
void print_err(char *name, char *cmd, int idx);

void handl_builtin(char **cmd, char **argv, int *status, int idx);
int is_builtin(char *cmd);
void exit_shell(char **cmd, char **argv, int *status, int idx);
void print_env(char **cmd, int *status);

int is_positive_number(char *std);
int _atoi(char *std);

#endif
