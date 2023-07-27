#include "main.h"
char *_strtok(char *str, const char *delim, char **last)
{
    char *token;
    if (str != NULL)
        *last = str;
    if (*last == NULL)
        return NULL;
    token = *last;
    *last += strspn(*last, delim);
    if (**last == '\0')
        *last = NULL;
    else
        *(*last)++ = '\0';
    return token;
}
