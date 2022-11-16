#include <stdio.h>

/**
 * main - print the arguments
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0.
 */

int main(int ac, char **av)
{
int i;

for (i = 0; *(av + i) != NULL; i++)
printf("%s\n", *(av + i));
return (0);
}
