#include "main.h"
/**
 * free_tokens - function to free the array of tokens
 * @tokens: the array of tokens
 * Return: it is void no return
 */
void free_tokens(char **tokens, int num_tokens)
{
int i = 0;
while (i < num_tokens)
{
free(tokens[i]);
i++;
}
free(tokens);
tokens = NULL;
return;
}
