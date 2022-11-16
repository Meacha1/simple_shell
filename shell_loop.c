#include "shell.h"

int _hsh(void)
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
printf("#cisfun/%s# ", pwd);
getline(&input, &n, stdin);
num_command = count_occurrence(input, ';');
command = tok_arg(input);
for (i = 0; i < (num_command+1); i++)
{
parsed = tok(command[i]);
if ((strcmp(parsed[0], "exit") == 0) && atoi(parsed[1]) >= INT_MIN && atoi(parsed[1]) <= INT_MAX)
                return (atoi(parsed[1]));
success = ececute(parsed);
}
}
return (0);
}
