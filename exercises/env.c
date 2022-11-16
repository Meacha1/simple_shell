#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[], char *envp[])
{
	printf("env = %s\n", getenv("PATH"));
	char **ptr = envp;
	int i;
	for (i = 0; ptr[i]; i++)
		printf("%s\n", ptr[i]);
	return (0);
}

