#include "main.h"
/**
 * tokenize_buffer - function to tokenize the buffer into array
 * @buffer_line: pointer of buffer line
 * Return: return the tokenized array
 */
char **tokenize_buffer(char *buffer_line)
{
char **tokens = NULL;
char *token = NULL;
int num_tokens = 0;
tokens = (char **) malloc(sizeof(char *) * MAX_BUFFER_SIZE);
token = strtok(buffer_line, " \t\n");
while (token != NULL)
{
tokens[num_tokens] = (char *) malloc(sizeof(char) * (strlen(token)) + 1);
_strcpy(tokens[num_tokens], token);
num_tokens++;
token = strtok(NULL, " \t\n");
}
tokens[num_tokens] = NULL;
return (tokens);
}
