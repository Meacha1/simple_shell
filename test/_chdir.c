#include "shell.h"

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
