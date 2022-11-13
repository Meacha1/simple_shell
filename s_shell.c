#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int _chdir(const char *path)
{
	if (path == NULL)
	{
		chdir("/root");
		return(1);
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
size_t i,j,k = 0;
    char *ptr = strdup(input);
    char delim[] = " \n";
    char **args;
    for (j = 0; j < strlen(input); j++)
      if(ptr[j] == ' ')
        {
          ptr[j] = '\0';
          k++;
        }
    args = malloc((k+2) * sizeof(char*));
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
