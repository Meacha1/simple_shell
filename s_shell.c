#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int _setenv(char *input)
{
size_t i, j, k = 0, l = 0;
char *ptr = strdup(input);
char delim[] = "=";
char **args;
for (j = 0; j < strlen(input); j++)
if (ptr[j] == '=')
{
ptr[j] = '\0';
k++;
if (ptr[j + 1] == ' ' || ptr[j - 1] == ' ')
return (0);
}
args = malloc((k + 2) * sizeof(char *));
for (i = 0; i < k + 1; i++)
{
args[i] = malloc(strlen(input));
for (j = 0; ptr[l + i] != '\0' && ptr[l + i] != '\n'; j++)
{
args[i][j] = ptr[l + i];
l++;
}
args[i] = realloc(args[i], sizeof(char) * (j + 1));
args[i][j] = '\0';
}
args[k + 1] = '\0';
setenv(args[0], args[1], 1);
return (1);
}
int _chdir(const char *path)
{
if (path == NULL)
{
chdir("/root");
return (1);
}
if (chdir(path) == -1)
{
printf("path not found\n");
}
return (0);
}
void _env(char **envp)
{
char **ptr = envp;
int i;
for (i = 0; ptr[i]; i++)
printf("%s\n", ptr[i]);
}
char **tok(char *input)
{
size_t i, j, k = 0, l = 0;
char *ptr = strdup(input);
char **args;
for (j = 0; j < strlen(input); j++)
if (ptr[j] == ' ')
{
ptr[j] = '\0';
k++;
}
args = malloc((k + 2) * sizeof(char *));
for (i = 0; i < k + 1; i++)
{
args[i] = malloc(strlen(input) + 1);
for (j = 0; ptr[l + i] != '\0' && ptr[l + i] != '\n'; j++)
{
args[i][j] = ptr[l + i];
l++;
}
args[i] = realloc(args[i], sizeof(char) * (j + 1));
args[i][j] = '\0';
}
args[k + 1] = NULL;
return (args);
}
int ececute(char **parsed)
{
pid_t pid;
int i;

if (parsed[1] == NULL && strchr(parsed[0], '=') != NULL)
{
i = _setenv(parsed[0]);
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
return (0);
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

int main(void)
{
int success = 1;
while (success)
{
char pwd[100];
size_t n = 0;
char **parsed;
char *input = NULL;
getcwd(pwd, 100);
printf("#cisfun/%s# ", pwd);
getline(&input, &n, stdin);
parsed = tok(input);
success = ececute(parsed);
}
return (0);
}
