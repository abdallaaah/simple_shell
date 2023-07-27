#include "main.h"
void execute_me(char **tokens, char *dot, int num_tokens, char *buffer_line)
{
    pid_t pid;
    int ret;
    (void)dot;

    if (access(tokens[0], X_OK) == -1)
    {
        char error_message[BUFSIZ];
        snprintf(error_message, BUFSIZ, "%s: %d: %s: not found\n", dot, 1, tokens[0]);
        write(STDOUT_FILENO, error_message, strlen(error_message));
        return;
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
}
