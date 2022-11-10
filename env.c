#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[], char *envp[])
{
	printf("TZ = %s\n", getenv("TZ"));
	char **ptr = envp;
	int i;
	for (i = 0; ptr[i]; i++)
		if( strcmp("HOME=/root", ptr[i])==0)	
		printf("%s\n", ptr[i]);
	return (0);
}

