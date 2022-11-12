#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t _getline (char **string, size_t *n, FILE *stream)
{
   int fd;
   int i = 0;
   fd = read(0, string[i], *n);
return (*n);
}

int main()
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Type something: ");
    characters = _getline(&buffer,&bufsize,stdin);
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);

    return(0);
}
