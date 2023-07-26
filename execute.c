#include "main.h"
/**
 * execute_me - execute the commands
 * @tokens: the tokinezed string hold the command from std input
 * @dot: carry the name of the bash
 * @num_tokens: number of tokens
 * Return: void no return
 */
void execute_me(char **tokens, char *dot, int num_tokens)
{
pid_t pid;
int ind;
char *argv[2];
/*char *env[] = {
"HOME=/root",
"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
NULL
};*/
(void)num_tokens;
argv[0] = tokens[0];
argv[1] = NULL;
pid = fork();
if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
ind = execve(argv[0], argv, env);
if (ind == -1)
{
perror(dot);
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
