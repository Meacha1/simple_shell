#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char **tok(char *input)
{
size_t i,j,k = 0,l = 0;
    char *ptr = strdup(input);
    char delim[] = " \n";
    for (j = 0; j < strlen(input); j++)
      if(ptr[j] == ' ')
        {
          ptr[j] = '\0';
          k++;
        }
    char **args = malloc((k+2) * sizeof(char*));
     args[0] = strtok(input, delim);
    for (i = 1; i < k+1; i++)
    {
        args[i] = strtok(NULL, delim);
    }
    args[i] = NULL;
    return (args);
}
int ececute(char **parsed)
{
       pid_t pid;
       if (strcmp(parsed[0], "exit") == 0)
	       return (0);
        pid = fork();
        if (pid == -1)
                printf("error forking");
        if (pid == 0)
        {
		int val = execvp(parsed[0], parsed);
        if (val == -1)
       {
         printf("error executing\n");
	 exit (1);
       }
	}
        else
        {
                wait(NULL);
        }
	return (1);
}

int main()
{
	int success = 1;
	while (success)
	{
		printf("#cisfun#> ");
		size_t n = 0;
		char *input = NULL;
		getline(&input, &n, stdin);
		char **parsed = tok(input);
		success = ececute(parsed);
}
return (0);
}
