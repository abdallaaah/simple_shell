#include "main.h"
/**
 * execute_me : function to execute commands
 * @tokens: array of the tokenized
 * @dot: program name
 * @num_tokens: numbers of tokens
 * @buffer_line: the buffer line
 * Return: depend on fork and many things
 */
int execute_me(char **tokens, char *dot, int num_tokens, char *buffer_line)
{

pid_t pid;
int ret, exit_flag = 0;
char *path_env, *dir;
char path[BUFSIZ], error_message[BUFSIZ];
(void)num_tokens, (void)dot, (void)exit_flag;
if (access(tokens[0], X_OK) == -1)
{
path_env = getenv("PATH");
dir = strtok(path_env, ":");
while (dir != NULL)
{
snprintf(path, BUFSIZ, "%s/%s", dir, tokens[0]);
if (access(path, X_OK) == 0)
{
tokens[0] = strdup(path);
break;
}
dir = strtok(NULL, ":");
}
if (access(tokens[0], X_OK) == -1)
{
exit_flag = 1;
snprintf(error_message, BUFSIZ, "%s: %d: %s: not found\n", dot, 1, tokens[0]);
write(STDOUT_FILENO, error_message, strlen(error_message));
/*return;*/
}
}
else
{
exit_flag = 1;
}
pid = fork();
if (pid == -1)
{
perror("fork error");
free_tokens(tokens, num_tokens);
free(buffer_line);
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
ret = execve(tokens[0], tokens, environ);
if (ret == -1)
{
perror("execve error");
free_tokens(tokens, num_tokens);
free(buffer_line);
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
return (exit_flag);
}
