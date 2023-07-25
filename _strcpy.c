#include "main.h"
/**
 * _strcpy - function to cput
 * @dest: the dest
 * @src: the source
 * Return: return the dest
 */
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
