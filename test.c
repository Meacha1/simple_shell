#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
        pid_t pid;
        pid_t ppid;

        pid = fork();

        if (pid == -1)
        {
                printf("unabele to fork\n");
                return (1);
        }
        if (pid == 0)
        {
                sleep(1);
                printf("\n#cisfun$");
        }
	else
      sleep(30);                          
       return (0);
}
