#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t _getline(char **string, size_t *n, FILE *stream)
{
	int fd, k, j = 0;
	char *dup = strdup(*string);
	*n = 120;
	while (1)
	{
		fd = read(0, dup, *n);
		for (k = 0; k < *n && dup[k] && dup[k] != '\n'; k++, j++)
			string[0][j] = dup[k];
		if (fd < *n)
			break;
	}
	string[0][j] = '\0';
	return (fd);
}
