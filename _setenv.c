#include "shell.h"

int _setenv(char *input)
{
size_t i, j, k = 0, l = 0;
char *ptr = strdup(input);
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
