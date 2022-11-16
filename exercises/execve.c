#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
       pid_t pid;
       int i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	for (i = 0; i < 5; i++)
	{
	pid = fork();
	if (pid == -1)
		printf("error forking");
	if (pid == 0)
	{
		printf("%d\n", getpid());
	int val = execve(argv[0], argv, NULL);

        if (val == -1)
        {
                printf("error\n");
        }
	}

	else
	{
		wait(NULL);
	printf("Done with execve\n");
	}
	}
        return (0);
}

