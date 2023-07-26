#include "main.h"
/**
 * _strcmp - function to compare string
 * @string1: the first string
 * @strng2: the second string
 * Return: 0 in case of they matching
 */
int _strcmp(const char *string1, const char *string2)
{
int i = 0;
while (string1[i] != '\0' && string2[2] != '\0' && string1[i] == string2[i])
{
i++;
}
return (string1[i] - string2[i]);
}
