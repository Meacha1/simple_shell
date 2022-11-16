#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char deli[] = {'/', '='};
	char *ptr;
	

	printf("%s\n",strtok(getenv("PATH"), deli));
	for (i = 0; ptr != NULL; i++)
	{
		ptr = strtok(NULL, deli);

		printf("%s\n", ptr);

	}
return (0);
	
}
