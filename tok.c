#include "shell.h"

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
