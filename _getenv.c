#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
char *_getenv(const char *name)
{
	char **ptr = environ;
	int i;
	char delimiter[] = "=";

	for (i = 0; ptr[i]; i++)
		if (strcmp(name, (strtok(ptr[i], delimiter))) == 0)
		{
			return (strtok(NULL, delimiter));
		}
	return (NULL);
}
int main(int argc, char *argv[], char *envp[])
{
	printf("HOME = %s\n", _getenv("HOME"));
	return (0);
}

