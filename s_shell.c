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
    for (j = 0; j < strlen(input); j++)
    {
      if(ptr[j] == ' ')
        {
          ptr[j] = '\0';
          k++;
        }
    }
    char **args = malloc((k+2) * sizeof(char*));
    for (i = 0; i < k+1; i++)
    {
        args[i] = malloc(strlen(input) + 1);
          for (j = 0; ptr[l+i] != '\0'; j++)
        {
          args[i][j] = ptr[l+i];
          l++;
        }
	  args[i][j] = '\0';
    }
    args[k+1] = NULL;
    return (args);
}
int ececute(char **parsed)
{
       pid_t pid;
       if (strcmp(parsed[0], "exit") == 0)
	       return(1);
        pid = fork();
        if (pid == -1)
                printf("error forking");
        if (pid == 0)
        {
		int val = execvp(parsed[0], parsed);
        if (val == -1)
       {
         printf("error executing\n");
       }
	}
        else
        {
                wait(NULL);
        }
}

int main()
{
	while (1)
	{
		size_t n = 120;
		char *input = NULL;
		getline(&input, &n, stdin);
		char **parsed = tok(input);
		ececute(parsed);
}
return (0);
}
