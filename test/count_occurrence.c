#include "shell.h"

int count_occurrence(char * str, char ch)
{
    int i, count=0;
    int len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i] == ch)
        {
           count++;
        }
    }
    return count;
}
