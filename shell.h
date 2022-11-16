#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

char **tok_arg(char *input);
int count_occurrence(char * str, char ch);
int _setenv(char *input);
int _chdir(const char *path);
void _env(char **envp);
char **tok(char *input);
int ececute(char **parsed);
int _hsh(char *input);

#endif
