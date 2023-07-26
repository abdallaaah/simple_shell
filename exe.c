#include "main.h"
void execute_me(char **tokens, char *dot, int num_tokens, char *buffer_line)
{
    pid_t pid;
    int ind;
    int i = 0;
    char *argv[2];
    (void)num_tokens;
    (void)dot;
    argv[0] = tokens[0];
    argv[1] = NULL;
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
        ind = execve(argv[0], argv, NULL);
        if (ind == -1)
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
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
    }
}
