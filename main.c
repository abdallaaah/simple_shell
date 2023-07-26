#include "main.h"
/**
 * main - Entry point
 * @argc: numbers of args
 * @argv: the argumnets will enter
 * Return: Always 0
 */
int flag = 0;
char *buffer_line = NULL;
void sigint_handler(int sig)
{
(void)sig;
flag = 1;
signal(SIGINT, sigint_handler);
if (buffer_line != NULL)
{
free(buffer_line);
buffer_line = NULL;
}
write(STDOUT_FILENO, "\n", 1);
exit(EXIT_SUCCESS);
}
int main(int argc, char *argv[])
{
/*char *buffer_line = NULL;*/
size_t buffer_len = 0;
char **tokens = NULL;
char *prompt = "#cisfun$ ";
ssize_t num;
int num_tokens;
(void)argc, (void)argv;
signal(SIGINT, sigint_handler);
while (1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, prompt, strlen(prompt));
num = getline(&buffer_line, &buffer_len, stdin);
if (num == -1)
{
if (errno ==  EINTR)
{
continue;
}
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
num_tokens++;
if (_strcmp(tokens[0], "exit") == 0)
{
free_tokens(tokens, num_tokens);
tokens = NULL;
free(buffer_line);
buffer_line = NULL;
exit(EXIT_SUCCESS);
}
if (flag != 1)
execute_me(tokens, argv[0], num_tokens, buffer_line);
free_tokens(tokens, num_tokens);
tokens = NULL;
}
free(buffer_line);
buffer_line = NULL;
tokens = NULL;
return (0);
}
