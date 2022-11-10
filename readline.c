#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	pid_t ppid;

	printf("Before fork\n");
	pid = fork();

	if (pid == -1)
	{
		printf("unabele to fork\n");
		return (1);
	}
	if (pid == 0)
	{
		sleep(3);
		printf("i am the child\n");
		printf("#cisfun$");
	}
	else
	{
		ppid = getppid();
		printf("i am the parent\n");
	printf("The parent pid: %d\n", ppid);
	}
	return (0);
}
