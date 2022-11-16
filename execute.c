#include "shell.h"

int ececute(char **parsed)
{
pid_t pid;

if (parsed[1] == NULL && strchr(parsed[0], '=') != NULL)
{
_setenv(parsed[0]);
return (3);
}
else if (parsed[1] != NULL && ((strchr(parsed[0], '=') != NULL) || (strchr(parsed[1], '=') != NULL)))
{
printf("%s command not found!\n", parsed[0]);
return (-3);
}
if (strcmp(parsed[0], "unset") == 0)
{
if (parsed[1] == NULL || strchr(parsed[1], '=') != NULL)
{
printf("failed to unset variable\n");
return (-5);
}
else
{
unsetenv(parsed[1]);
return (5);
}
}
if (strcmp(parsed[0], "cd") == 0)
{
_chdir(parsed[1]);
return (2);
}
if (strcmp(parsed[0], "exit") == 0)
{
if(parsed[1] == NULL)
return (0);
}
if (strcmp(parsed[0], "env") == 0)
{
_env(parsed);
}
pid = fork();
if (pid == -1)
printf("error forking");
if (pid == 0)
{
int val = execvp(parsed[0], parsed);
if (val == -1)
{
printf("error executing\n");
exit(1);
}
}
else
{
wait(NULL);
}
return (1);
}
