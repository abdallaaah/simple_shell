#include "main.h"
#include "main.h"
char *_strcpy(char *dest, const char *src)
{
char *p = dest;
while (*src)
{
*p++ = *src++;
}
*p = '\0';
return (dest);
}
