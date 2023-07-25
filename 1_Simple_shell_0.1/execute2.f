#include "main.h"
/**
 * execute_me - execute the commands
 * @tokens: the tokinezed string hold the command from std input
 * @dot: carry the name of the bash
 * Return: void no return
 */
void execute_me(char **tokens, char *dot)
{
pid_t pid;
int ind;
char *argv[] = {tokens[0], NULL};
pid = fork();
if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
ind = execve(argv[0], argv, NULL);
if (ind == -1)
{
perror(dot);
exit(EXIT_FAILURE);
}
if (pid != 0)
{
wait(NULL);
}
}
}
