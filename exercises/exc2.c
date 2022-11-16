#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void exc(char *argv[])
{
       pid_t pid;
       argv[0] = {"/bin/ls"};
       pid = fork();
        if (pid == -1)
                printf("error forking");
        if (pid == 0)
        {
        int val = execve(argv[0], "-l", "/tmp", NULL);
	}
        if (val == -1)
        {
                printf("error\n");
        }
        }
}
int main(int argc, char *argv[])
{
	int i = 0;
	while(i < 5)
	{
		i++;
		exc(argv);
	}
	return (0);
}
