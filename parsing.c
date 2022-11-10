#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char **tok(char *input)
{
    size_t i,j,k = 0,l = 0;
    char *ptr = strdup(input);
    for (j = 0; j < strlen(input); j++)
    {
      if(ptr[j] == ' ')
        {
          ptr[j] = '\0';
          k++;
        }
    }
    char **args = malloc((k+2) * sizeof(char*));
    for (i = 0; i < k+1; i++)
    {
        args[i] = malloc(sizeof(input));
          for (j = 0; ptr[l+i] != '\0'; j++)
        {
          args[i][j] = ptr[l+i];
          l++;
        }
    }
    args[k+1] = NULL;
    return (args);
}

int main() {
char *input = {"ab cde 1 bn amm"};
char **persed = tok(input);

    return 0;
}
