#include "shell.h"

char **tok_arg(char *input)
{
size_t i, j, y = 0, x = 0, k = 0, l = 0;
char *ptr = strdup(input);
char **args;
for (j = 0; j < strlen(input); j++)
if (ptr[j] == ';')
{
  ptr[j] = '\0';
  k++;
  y++;
  if (ptr[j + 1] == ' ')
  {
  ptr[j + 1] = '\0';
  k++;
  }
  if (ptr[j - 1] == ' ')
  {
  ptr[j - 1] = '\0';
  k++;
  }
}
args = malloc((y + 2) * sizeof(char *));
for (i = 0; i < k + 1; i++)
{
  if (ptr[l + i] == '\0')
  {
  x++;
  continue;
  }
args[i-x] = malloc(strlen(input) + 1);
for (j = 0; ptr[l + i] != '\0' && ptr[l + i] != '\n'; j++)
{
args[i - x][j] = ptr[l + i];
l++;
}
args[i - x] = realloc(args[i - x], sizeof(char) * (j + 1));
args[i - x][j] = '\0';
}
args[y + 1] = NULL;
return (args);
}
