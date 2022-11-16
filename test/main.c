#include "shell.h"

int main(void)
{
int success = 1;
while (success)
{
char pwd[100];
size_t n = 0;
int i;
char **command;
char **parsed;
char *input = NULL;
int num_command;
getcwd(pwd, 100);
printf("%s$ ", pwd);
getline(&input, &n, stdin);
num_command = count_occurrence(input, ';');
command = tok_arg(input);
for (i = 0; i < (num_command+1); i++)
{
parsed = tok(command[i]);
if ((strcmp(parsed[0], "exit") == 0) && parsed[1] != NULL && atoi(parsed[1]) >= INT_MIN && atoi(parsed[1]) <= INT_MAX)
                return (atoi(parsed[1]));
else
success = ececute(parsed);
}
}
return (0);
}

