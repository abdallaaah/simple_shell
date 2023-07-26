#include "main.h"
void execute_me(char **tokens, char *dot, int num_tokens, char *buffer_line)
{
    pid_t pid;
    int i = 0;
    int ret;
    (void)num_tokens;
    (void)dot;

    if (access(tokens[0], X_OK) == -1)
    {
        char error_message[BUFSIZ];
        snprintf(error_message, BUFSIZ, "%s: %d: %s: not found\n", dot, 1, tokens[0]);
        for (i = 0; i < num_tokens; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
        free(buffer_line);
        write(STDOUT_FILENO, error_message, strlen(error_message));
        return;
    }

    ret = execve(tokens[0], tokens, NULL);
    if (ret == -1)
    {
        perror("execve error");
        for (i = 0; i < num_tokens; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
        free(buffer_line);
        exit(EXIT_FAILURE);
    }
    else
    {
        pid = fork();
        if (pid == -1)
        {
            for (i = 0; i < num_tokens; i++)
            {
                free(tokens[i]);
            }
            free(tokens);
            free(buffer_line);
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            if (execve(tokens[0], tokens, NULL) == -1)
            {
                perror("execve error");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            waitpid(pid, NULL, 0);
        }
    }
}
