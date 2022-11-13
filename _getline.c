#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t _getline (char **string, size_t *n, FILE *stream)
{
   int fd;
   char *dup = strdup(*string);
   int j = 0;
   int k;
   *n = 1024;
   while(1)
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
int main()
{
    char *buffer;
    size_t bufsize = 0;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Type something: ");
    fflush(stdout);
    characters = _getline(&buffer,&bufsize,stdin);
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);
    return(0);
}
