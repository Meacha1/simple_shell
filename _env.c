#include "shell.h"

void _env(char **envp)
{
char **ptr = envp;
int i;
for (i = 0; ptr[i]; i++)
printf("%s\n", ptr[i]);
}
