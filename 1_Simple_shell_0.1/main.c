#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
char *buffer_line = NULL;
size_t buffer_len = 0;
char **tokens = NULL;
char *prompt = "#cisfun$ ";
ssize_t num;
int i, num_tokens;
(void)argc;
(void)argv;
if (argc > 1)
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
while (1)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, prompt, strlen(prompt));
}
num = getline(&buffer_line, &buffer_len, stdin);
if (num == -1)
{
if (EOF)
{
break;
}
else
{
perror("Error in getline()"), exit(EXIT_FAILURE);
continue;
}
}
tokens = tokenize_buffer(buffer_line);
num_tokens = 0;
while (tokens[num_tokens] != NULL)
{
num_tokens++;
}
execute_me(tokens, argv[0], num_tokens);
for (i = 0; i < num_tokens; i++)
{
/*printf("token[%d]: %s\n", i, tokens[i]);*/
free(tokens[i]);
}
free(tokens);
}
free(buffer_line);
return (0);
}
