#include <stdio.h>
#include <unistd.h>

/**
 * main - print the arguments
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0.
 */

int main(int ac, char **av)
{
pid_t pid = getpid();
pid_t ppid = getppid();

printf("%d\n", pid);
printf("%d\n", ppid);

return (0);
}
